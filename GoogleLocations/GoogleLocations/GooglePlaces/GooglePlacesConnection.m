//
//  GooglePlacesConnection.m
// 
// Copyright 2011 Joshua Drew
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import "GooglePlacesConnection.h"
#import "MKNetworkKit.h"
#import "JSONKit.h"

@implementation GooglePlacesConnection

- (id)initWithDelegate:(id <GooglePlacesConnectionDelegate>)del andApiKey:(NSString *)apiKey
{
    self = [super init];
    if (!self) return nil;
    [self setDelegate:del];
    [self setApiKey:apiKey];
    return self;
}

- (id)init
{
    NSLog(@"need a delegate and an ApiKey!! use initWithDelegate: andApiKey:!");
    return nil;
}


//Method is called to load initial search
- (void)getGoogleObjects:(CLLocationCoordinate2D)coords andTypes:(NSString *)types
{
    if (!self.apiKey || [self.apiKey isEqualToString:@""])
    {
        [self.delegate googlePlacesConnection:self didFailWithError:[[NSError alloc] initWithDomain:@"GoogleApiKeyMissing" code:-1 userInfo:@{NSLocalizedDescriptionKey: @"The Google API Key is missing. Don't forget to use one with setApiKey or in the initWithDelegate: andApiKey:"}]];
        return;
    }

    //NEW setting userlocation to the coords passed in for later use
    self.userLocation = coords;

    double centerLat = coords.latitude;
    double centerLng = coords.longitude;

    types = [types mk_urlEncodedString];

    NSString *gurl = [NSString stringWithFormat:@"https://maps.googleapis.com/maps/api/place/nearbysearch/json?location=%f,%f&radius=50000&types=%@&sensor=true&language=%@&key=%@",
                                                centerLat, centerLng, types, [[NSLocale preferredLanguages] objectAtIndex:0], self.apiKey];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:gurl]
                                                           cachePolicy:NSURLRequestUseProtocolCachePolicy
                                                       timeoutInterval:10];

    [self cancelGetGoogleObjects];

    self.connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:YES];

    if (self.connection)
    {
        self.responseData = [NSMutableData data];
        self.connectionIsActive = YES;
    }
    else
    {
        NSLog(@"connection failed");
    }

}

//Method is called during UISearchBar search
- (void)getGoogleObjectsWithQuery:(NSString *)query
                   andCoordinates:(CLLocationCoordinate2D)coords
                         andTypes:(NSString *)types
{
    if (!self.apiKey || [self.apiKey isEqualToString:@""])
    {
        [self.delegate googlePlacesConnection:self didFailWithError:[[NSError alloc] initWithDomain:@"GoogleApiKeyMissing" code:-1 userInfo:@{NSLocalizedDescriptionKey: @"The Google API Key is missing. Don't forget to use one with setApiKey or in the initWithDelegate: andApiKey:"}]];
        return;
    }

    //NEW setting userlocation to the coords passed in for later use
    self.userLocation = coords;

    double centerLat = coords.latitude;
    double centerLng = coords.longitude;

    query = [query mk_urlEncodedString];
    types = [types mk_urlEncodedString];

    NSString *gurl = [NSString stringWithFormat:@"https://maps.googleapis.com/maps/api/place/textsearch/json?location=%f,%f&radius=50000&types=%@&query=%@&sensor=true&language=%@&key=%@",
                                                centerLat, centerLng, types, query, [[NSLocale preferredLanguages] objectAtIndex:0], self.apiKey];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:gurl]
                                                           cachePolicy:NSURLRequestUseProtocolCachePolicy
                                                       timeoutInterval:10];

    [self cancelGetGoogleObjects];

    self.connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:YES];

    if (self.connection)
    {
        self.responseData = [NSMutableData data];
        self.connectionIsActive = YES;
    }
    else
    {
        NSLog(@"connection failed");
    }
}

//Method is called to get details of place
- (void)getGoogleObjectDetails:(NSString *)reference
{
    if (!self.apiKey || [self.apiKey isEqualToString:@""])
    {
        [self.delegate googlePlacesConnection:self didFailWithError:[[NSError alloc] initWithDomain:@"GoogleApiKeyMissing" code:-1 userInfo:@{NSLocalizedDescriptionKey: @"The Google API Key is missing. Don't forget to use one with setApiKey or in the initWithDelegate: andApiKey:"}]];
        return;
    }

    NSString *gurl = [NSString stringWithFormat:@"https://maps.googleapis.com/maps/api/place/details/json?reference=%@&sensor=true&key=%@",
                                                reference, self.apiKey];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:gurl]
                                                           cachePolicy:NSURLRequestUseProtocolCachePolicy
                                                       timeoutInterval:10];

    [self cancelGetGoogleObjects];

    self.connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:YES];

    if (self.connection)
    {
        self.responseData = [NSMutableData data];
        self.connectionIsActive = YES;
    }
    else
    {
        NSLog(@"connection failed");
    }

}

- (void)connection:(NSURLConnection *)conn didReceiveResponse:(NSURLResponse *)response
{
    [self.responseData setLength:0];
}

- (void)connection:(NSURLConnection *)conn didReceiveData:(NSData *)data
{
    [self.responseData appendData:data];
}

- (void)connection:(NSURLConnection *)conn didFailWithError:(NSError *)error
{
    self.connectionIsActive = NO;
    [self.delegate googlePlacesConnection:self didFailWithError:error];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)conn
{
    self.connectionIsActive = NO;
    NSString *responseString = [[NSString alloc] initWithData:self.responseData encoding:NSUTF8StringEncoding];
    NSError *jsonError = nil;

    NSDictionary *parsedJSON = [responseString objectFromJSONString];

    if ([jsonError code] == 0)
    {
        NSString *responseStatus = [NSString stringWithFormat:@"%@", [parsedJSON objectForKey:@"status"]];

        if ([responseStatus isEqualToString:@"OK"])
        {
            if ([parsedJSON objectForKey:@"results"] == nil)
            {
                //Perform Place Details results
                NSDictionary *gResponseDetailData = [parsedJSON objectForKey:@"result"];
                NSMutableArray *googlePlacesDetailObject = [NSMutableArray arrayWithCapacity:1];  //Hard code since ONLY 1 result will be coming back

                GooglePlacesObject *detailObject = [[GooglePlacesObject alloc] initWithJsonResultDict:gResponseDetailData andUserCoordinates:self.userLocation];
                [googlePlacesDetailObject addObject:detailObject];

                [self.delegate googlePlacesConnection:self didFinishLoadingWithGooglePlacesObjects:googlePlacesDetailObject];

            }
            else
            {
                //Perform Place Search results
                NSDictionary *gResponseData = [parsedJSON objectForKey:@"results"];
                NSMutableArray *googlePlacesObjects = [NSMutableArray arrayWithCapacity:[[parsedJSON objectForKey:@"results"] count]];

                for (NSDictionary *result in gResponseData)
                {
                    [googlePlacesObjects addObject:result];
                }

                for (int x = 0; x < [googlePlacesObjects count]; x++)
                {
                    GooglePlacesObject *object = [[GooglePlacesObject alloc] initWithJsonResultDict:[googlePlacesObjects objectAtIndex:x] andUserCoordinates:self.userLocation];
                    [googlePlacesObjects replaceObjectAtIndex:x withObject:object];
                }

                [self.delegate googlePlacesConnection:self didFinishLoadingWithGooglePlacesObjects:googlePlacesObjects];

            }

        }
        else if ([responseStatus isEqualToString:@"ZERO_RESULTS"])
        {
            NSString *description = nil;
            int errCode;

            description = NSLocalizedString(@"No locations were found.", @"");
            errCode = 404;

            // Make underlying error.
            NSError *underlyingError = [[NSError alloc] initWithDomain:NSPOSIXErrorDomain
                                                                  code:errno userInfo:nil];
            // Make and return custom domain error.
            NSArray *objArray = [NSArray arrayWithObjects:description, underlyingError, nil];
            NSArray *keyArray = [NSArray arrayWithObjects:NSLocalizedDescriptionKey,
                                                          NSUnderlyingErrorKey, nil];
            NSDictionary *eDict = [NSDictionary dictionaryWithObjects:objArray
                                                              forKeys:keyArray];

            NSError *responseError = [NSError errorWithDomain:@"GoogleLocalObjectDomain"
                                                         code:errCode
                                                     userInfo:eDict];

            [self.delegate googlePlacesConnection:self didFailWithError:responseError];
        }
        else
        {
            // no results
            NSString *responseDetails = [NSString stringWithFormat:@"%@", [parsedJSON objectForKey:@"status"]];
            NSError *responseError = [NSError errorWithDomain:@"GoogleLocalObjectDomain"
                                                         code:500
                                                     userInfo:[NSDictionary dictionaryWithObjectsAndKeys:responseDetails, @"NSLocalizedDescriptionKey", nil]];

            [self.delegate googlePlacesConnection:self didFailWithError:responseError];
        }
    }
    else
        [self.delegate googlePlacesConnection:self didFailWithError:jsonError];
}

- (void)cancelGetGoogleObjects
{
    if (self.connectionIsActive == YES)
        self.connectionIsActive = NO;
}
@end
