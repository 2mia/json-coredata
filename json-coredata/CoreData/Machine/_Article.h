// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to Article.h instead.

#import <CoreData/CoreData.h>


extern const struct ArticleAttributes {
	__unsafe_unretained NSString *id;
} ArticleAttributes;

extern const struct ArticleRelationships {
	__unsafe_unretained NSString *issues;
} ArticleRelationships;

extern const struct ArticleFetchedProperties {
} ArticleFetchedProperties;

@class Issue;



@interface ArticleID : NSManagedObjectID {}
@end

@interface _Article : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (ArticleID*)objectID;





@property (nonatomic, strong) NSString* id;



//- (BOOL)validateId:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSSet *issues;

- (NSMutableSet*)issuesSet;





@end

@interface _Article (CoreDataGeneratedAccessors)

- (void)addIssues:(NSSet*)value_;
- (void)removeIssues:(NSSet*)value_;
- (void)addIssuesObject:(Issue*)value_;
- (void)removeIssuesObject:(Issue*)value_;

@end

@interface _Article (CoreDataGeneratedPrimitiveAccessors)


- (NSString*)primitiveId;
- (void)setPrimitiveId:(NSString*)value;





- (NSMutableSet*)primitiveIssues;
- (void)setPrimitiveIssues:(NSMutableSet*)value;


@end
