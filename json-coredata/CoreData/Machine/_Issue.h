// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to Issue.h instead.

#import <CoreData/CoreData.h>


extern const struct IssueAttributes {
} IssueAttributes;

extern const struct IssueRelationships {
	__unsafe_unretained NSString *article;
	__unsafe_unretained NSString *tags;
} IssueRelationships;

extern const struct IssueFetchedProperties {
} IssueFetchedProperties;

@class Article;
@class NSManagedObject;


@interface IssueID : NSManagedObjectID {}
@end

@interface _Issue : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (IssueID*)objectID;





@property (nonatomic, strong) Article *article;

//- (BOOL)validateArticle:(id*)value_ error:(NSError**)error_;




@property (nonatomic, strong) NSSet *tags;

- (NSMutableSet*)tagsSet;





@end

@interface _Issue (CoreDataGeneratedAccessors)

- (void)addTags:(NSSet*)value_;
- (void)removeTags:(NSSet*)value_;
- (void)addTagsObject:(NSManagedObject*)value_;
- (void)removeTagsObject:(NSManagedObject*)value_;

@end

@interface _Issue (CoreDataGeneratedPrimitiveAccessors)



- (Article*)primitiveArticle;
- (void)setPrimitiveArticle:(Article*)value;



- (NSMutableSet*)primitiveTags;
- (void)setPrimitiveTags:(NSMutableSet*)value;


@end
