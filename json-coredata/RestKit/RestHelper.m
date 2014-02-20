//
//  RestHelper.m
//  mobile
//
//  Created by Mihai Iancu on 5/25/13.
//  Copyright (c) 2013 eugenol. All rights reserved.
//

#import "RestHelper.h"

#import "Issue.h"
#import "Article.h"

static RKObjectManager* _manager;

@implementation RestHelper
+(RKObjectManager*)manager {
    return [RKObjectManager sharedManager] ;
}

+(void)setupRestKit{
    
#ifdef DEBUG
    RKLogConfigureByName("RestKit/Network", RKLogLevelDebug);
    RKLogConfigureByName("RestKit/ObjectMapping", RKLogLevelDebug);
#endif
    
    RKObjectManager *manager = _manager = [RKObjectManager managerWithBaseURL:
                                           [NSURL URLWithString:@"http://localhost:3000"]];
    
    NSManagedObjectModel *managedObjectModel = [NSManagedObjectModel mergedModelFromBundles:nil];
    RKManagedObjectStore *managedObjectStore = [[RKManagedObjectStore alloc] initWithManagedObjectModel:managedObjectModel];
    manager.managedObjectStore = managedObjectStore;
    
    
    RKEntityMapping *issueMapping = [RKEntityMapping mappingForEntityForName:NSStringFromClass([Issue class]) inManagedObjectStore:manager.managedObjectStore];
    issueMapping.identificationAttributes = @[ @"id" ];
    [issueMapping addAttributeMappingsFromArray: @[@"id", @"title"]];

    
    RKEntityMapping *articleMapping = [RKEntityMapping mappingForEntityForName:NSStringFromClass([Article class]) inManagedObjectStore:manager.managedObjectStore];
    articleMapping.identificationAttributes = @[ @"id" ];
//    [contactMapping addAttributeMappingsFromArray: @[@"name", @"isPrimary", @"active", @"content", @"type"]];

    
//  [articleMapping addConnectionForRelationship:@"issue" connectedBy:@{ @"cabinetId" : @"rid" }];
    
    
    // Register our mappings with the provider
    [manager addResponseDescriptorsFromArray:@[
    [RKResponseDescriptor responseDescriptorWithMapping:issueMapping
                                             pathPattern:@"/issues"
                                                 keyPath:@""
                                             statusCodes:RKStatusCodeIndexSetForClass(RKStatusCodeClassSuccessful)]
     ]];
    
    /**
     Complete Core Data stack initialization
     */
    [managedObjectStore createPersistentStoreCoordinator];
    
    NSString *storePath = [RKApplicationDataDirectory() stringByAppendingPathComponent:@"someData4.sqlite"];
    
    NSError *error;
    
    NSPersistentStore *persistentStore = [managedObjectStore addSQLitePersistentStoreAtPath:storePath fromSeedDatabaseAtPath:nil  withConfiguration:nil options:@{NSMigratePersistentStoresAutomaticallyOption:@YES, NSInferMappingModelAutomaticallyOption:@YES} error:&error];
    
    NSAssert(persistentStore, @"Failed to add persistent store with error: %@", error);
    
    // Create the managed object contexts
    [managedObjectStore createManagedObjectContexts];
    
    // Configure a managed object cache to ensure we do not create duplicate objects
    managedObjectStore.managedObjectCache = [[RKInMemoryManagedObjectCache alloc] initWithManagedObjectContext:managedObjectStore.persistentStoreManagedObjectContext];
    
    // Update from remote
    [manager.router.routeSet addRoute:[RKRoute routeWithClass:[Issue class] pathPattern:@"/issues/:id" method:RKRequestMethodGET]];

    //[RestHelper registerDeleteHandlers];
    
    [RestHelper loadIssues];
    
    [manager setRequestSerializationMIMEType:RKMIMETypeJSON];
}

+(void)loadIssues{
    [[RKObjectManager sharedManager] getObjectsAtPath:@"/issues"
                                           parameters:@{}
                                              success:nil
                                              failure:^(RKObjectRequestOperation *operation, NSError *error) {
                                                  NSLog(@"Error: %@",error);
                                              }];
}

+(void)registerDeleteHandlers{
    [[RestHelper manager] addFetchRequestBlock:^NSFetchRequest *(NSURL *URL) {
        RKPathMatcher *pathMatcher = [RKPathMatcher pathMatcherWithPattern:@"/issues/"];
        NSDictionary *args = nil;
        BOOL match = [pathMatcher matchesPath:[URL relativePath] tokenizeQueryStrings:NO parsedArguments:&args];

        if (!match)
            return nil;
        
        NSFetchRequest *fetchRequest = [NSFetchRequest fetchRequestWithEntityName:NSStringFromClass([Issue class])];
        return fetchRequest;
    }];
}
@end
