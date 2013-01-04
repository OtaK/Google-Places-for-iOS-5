//
//  GooglePlacesObject.h
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

#import <Foundation/Foundation.h>

#define	kLocationAccounting	@"accounting"
#define	kLocationAirport	@"airport"
#define	kLocationAmusementPark	@"amusement_park"
#define	kLocationAquarium	@"aquarium"
#define	kLocationArtGallery	@"art_gallery"
#define	kLocationAtm	@"atm"
#define	kLocationBakLocationEry	@"bakLocationEry"
#define	kLocationBank	@"bank"
#define	kLocationBar	@"bar"
#define	kLocationBeautySalon	@"beauty_salon"
#define	kLocationBicycleStore	@"bicycle_store"
#define	kLocationBookLocationStore	@"book_store"
#define	kLocationBowlingAlley	@"bowling_alley"
#define	kLocationBusStation	@"bus_station"
#define	kLocationCafe	@"cafe"
#define	kLocationCampground	@"campground"
#define	kLocationCarDealer	@"car_dealer"
#define	kLocationCarRental	@"car_rental"
#define	kLocationCarRepair	@"car_repair"
#define	kLocationCarWash	@"car_wash"
#define	kLocationCasino	@"casino"
#define	kLocationCemetery	@"cemetery"
#define	kLocationChurch	@"church"
#define	kLocationCityHall	@"city_hall"
#define	kLocationClothingStore	@"clothing_store"
#define	kLocationConvenienceStore	@"convenience_store"
#define	kLocationCourthouse	@"courthouse"
#define	kLocationDentist	@"dentist"
#define	kLocationDepartmentStore	@"department_store"
#define	kLocationDoctor	@"doctor"
#define	kLocationElectrician	@"electrician"
#define	kLocationElectronicsStore	@"electronics_store"
#define	kLocationEmbassy	@"embassy"
#define	kLocationEstablishment	@"establishment"
#define	kLocationFinance	@"finance"
#define	kLocationFireStation	@"fire_station"
#define	kLocationFlorist	@"florist"
#define	kLocationFood	@"food"
#define	kLocationFuneralHome	@"funeral_home"
#define	kLocationFurnitureStore	@"furniture_store"
#define	kLocationGasStation	@"gas_station"
#define	kLocationGeneralContractor	@"general_contractor"
#define	kLocationGeocode	@"geocode"
#define	kLocationGrocerySupermarkLocationEt	@"grocery_or_supermarkLocationEt"
#define	kLocationGym	@"gym"
#define	kLocationHairCare	@"hair_care"
#define	kLocationHardwareStore	@"hardware_store"
#define	kLocationHealth	@"health"
#define	kLocationHindu_temple	@"hindu_temple"
#define	kLocationHomeGoodsStore	@"home_goods_store"
#define	kLocationHospital	@"hospital"
#define	kLocationInsuranceAgency	@"insurance_agency"
#define	kLocationJewelryStore	@"jewelry_store"
#define	kLocationLaundry	@"laundry"
#define	kLocationLawyer	@"lawyer"
#define	kLocationLibrary	@"library"
#define	kLocationLiquorStore	@"liquor_store"
#define	kLocationLocalGovernmentOffice	@"local_government_office"
#define	kLocationLockLocationSmith	@"lockLocationSmith"
#define	kLocationLodging	@"lodging"
#define	kLocationMealDelivery	@"meal_delivery"
#define	kLocationMealTakLocationEaway	@"meal_takLocationEaway"
#define	kLocationMosque	@"mosque"
#define	kLocationMovieTental	@"movie_rental"
#define	kLocationMovieTheater	@"movie_theater"
#define	kLocationMovingCompany	@"moving_company"
#define	kLocationMuseum	@"museum"
#define	kLocationNightClub	@"night_club"
#define	kLocationPainter	@"painter"
#define	kLocationPark	@"park"
#define	kLocationParking	@"parking"
#define	kLocationPetStore	@"pet_store"
#define	kLocationPharmacy	@"pharmacy"
#define	kLocationPhysiotherapist	@"physiotherapist"
#define	kLocationPlaceWorship	@"place_of_worship"
#define	kLocationPlumber	@"plumber"
#define	kLocationPolice	@"police"
#define	kLocationPostOffice	@"post_office"
#define	kLocationRealEstateAgency	@"real_estate_agency"
#define	kLocationRestaurant	@"restaurant"
#define	kLocationRoofingContractor	@"roofing_contractor"
#define	kLocationRvPark	@"rv_park"
#define	kLocationSchool	@"school"
#define	kLocationShoeStore	@"shoe_store"
#define	kLocationShoppingMall	@"shopping_mall"
#define	kLocationSpa	@"spa"
#define	kLocationStadium	@"stadium"
#define	kLocationStorage	@"storage"
#define	kLocationStore	@"store"
#define	kLocationSubwayStation	@"subway_station"
#define	kLocationSynagogue	@"synagogue"
#define	kLocationTaxiStand	@"taxi_stand"
#define	kLocationTrainStation	@"train_station"
#define	kLocationTravelAgency	@"travel_agency"
#define	kLocationUniversity	@"university"
#define	kLocationVeterinaryCare	@"veterinary_care"
#define	kLocationZoo	@"zoo"
#define kLocationAll S(@"%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@|%@", kLocationAccounting, kLocationAirport, kLocationAmusementPark, kLocationAquarium, kLocationArtGallery, kLocationAtm, kLocationBakLocationEry, kLocationBank, kLocationBar, kLocationBeautySalon, kLocationBicycleStore, kLocationBookLocationStore, kLocationBowlingAlley, kLocationBusStation, kLocationCafe, kLocationCampground, kLocationCarDealer, kLocationCarRental, kLocationCarRepair, kLocationCarWash, kLocationCasino, kLocationCemetery, kLocationChurch, kLocationCityHall, kLocationClothingStore, kLocationConvenienceStore, kLocationCourthouse, kLocationDentist, kLocationDepartmentStore, kLocationDoctor, kLocationElectrician, kLocationElectronicsStore, kLocationEmbassy, kLocationEstablishment, kLocationFinance, kLocationFireStation, kLocationFlorist, kLocationFood, kLocationFuneralHome, kLocationFurnitureStore, kLocationGasStation, kLocationGeneralContractor, kLocationGeocode, kLocationGrocerySupermarkLocationEt, kLocationGym, kLocationHairCare, kLocationHardwareStore, kLocationHealth, kLocationHindu_temple, kLocationHomeGoodsStore, kLocationHospital, kLocationInsuranceAgency, kLocationJewelryStore, kLocationLaundry, kLocationLawyer, kLocationLibrary, kLocationLiquorStore, kLocationLocalGovernmentOffice, kLocationLockLocationSmith, kLocationLodging, kLocationMealDelivery, kLocationMealTakLocationEaway, kLocationMosque, kLocationMovieTental, kLocationMovieTheater, kLocationMovingCompany, kLocationMuseum, kLocationNightClub, kLocationPainter, kLocationPark, kLocationParking, kLocationPetStore, kLocationPharmacy, kLocationPhysiotherapist, kLocationPlaceWorship, kLocationPlumber, kLocationPolice, kLocationPostOffice, kLocationRealEstateAgency, kLocationRestaurant, kLocationRoofingContractor, kLocationRvPark, kLocationSchool, kLocationShoeStore, kLocationShoppingMall, kLocationSpa, kLocationStadium, kLocationStorage, kLocationStore, kLocationSubwayStation, kLocationSynagogue, kLocationTaxiStand, kLocationTrainStation, kLocationTravelAgency, kLocationUniversity, kLocationVeterinaryCare, kLocationZoo)


@interface GooglePlacesObject : NSObject
{
    NSString    *placesId;
    NSString    *reference;
    NSString    *name;
    NSString    *icon;
    NSString    *rating;
    NSString    *vicinity;
    NSArray     *type; //array
    NSString    *url;
    NSArray     *addressComponents; //array
    NSString    *formattedAddress;
    NSString    *formattedPhoneNumber; 
    NSString    *website;
    NSString    *internationalPhoneNumber;
    NSString    *searchTerms;
    CLLocationCoordinate2D coordinate;
    //NEW
    NSString    *distanceInFeetString;
    NSString    *distanceInMilesString;
    
}

@property (nonatomic, retain) NSString    *placesId;
@property (nonatomic, retain) NSString    *reference;
@property (nonatomic, retain) NSString    *name;
@property (nonatomic, retain) NSString    *icon;
@property (nonatomic, retain) NSString    *rating;
@property (nonatomic, retain) NSString    *vicinity;
@property (nonatomic, retain) NSArray     *type; //array
@property (nonatomic, retain) NSString    *url;
@property (nonatomic, retain) NSArray     *addressComponents; //array
@property (nonatomic, retain) NSString    *formattedAddress;
@property (nonatomic, retain) NSString    *formattedPhoneNumber;
@property (nonatomic, retain) NSString    *website;
@property (nonatomic, retain) NSString    *internationalPhoneNumber;
@property (nonatomic, retain) NSString      *searchTerms;
@property (nonatomic, assign) CLLocationCoordinate2D    coordinate;
//NEW
@property (nonatomic, retain) NSString    *distanceInFeetString;
@property (nonatomic, retain) NSString    *distanceInMilesString;

- (id)initWithJsonResultDict:(NSDictionary *)jsonResultDict andUserCoordinates:(CLLocationCoordinate2D)userCoords;
- (id)initWithJsonResultDict:(NSDictionary *)jsonResultDict searchTerms:(NSString *)terms andUserCoordinates:(CLLocationCoordinate2D)userCoords;

- (id)initWithName:(NSString *)name
          latitude:(double)lt 
         longitude:(double)lg 
         placeIcon:(NSString *)icn               
            rating:(NSString *)rate            
          vicinity:(NSString *)vic       
              type:(NSString *)typ 
         reference:(NSString *)ref 
               url:(NSString *)www
 addressComponents:(NSString *)addComp 
  formattedAddress:(NSArray *)fAddrss
formattedPhoneNumber:(NSString *)fPhone
           website:(NSString *)web
internationalPhone:(NSString *)intPhone
       searchTerms:(NSString *)search
    distanceInFeet:(NSString *)distanceFeet
   distanceInMiles:(NSString *)distanceMiles;



@end
