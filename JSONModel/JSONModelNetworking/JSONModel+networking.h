//
//  JSONModel+networking.h
//
//  @version 0.7
//  @author Marin Todorov, http://www.touch-code-magazine.com
//

// Copyright (c) 2012 Marin Todorov, Underplot ltd.
// This code is distributed under the terms and conditions of the MIT license.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// The MIT License in plain English: http://www.touch-code-magazine.com/JSONModel/MITLicense

#import "JSONModel.h"
#import "JSONHTTPClient.h"

typedef void(^JSONModelBlock)(JSONModel* model);

/**
 * The JSONModel(networking) class category adds networking to JSONModel.
 * It adds initFromURLWithString: initializer, which makes a GET http request 
 * to the URL given and initializes the model with the returned JSON.
 * Use #import "JSONModel+networking.h" to import networking capabilities.
 */
@interface JSONModel(networking)

@property (assign, nonatomic) BOOL isLoading;

/**
 * Create a new model instance and initialize it with the JSON fetched from the given URL
 * @param urlString the absolute URL address of the JSON feed as a string
 * @exception JSONModelTypeNotAllowedException thrown when unsported type is found in the incoming JSON, or a property type in your model is not supported by JSONValueTransformer and its categories
 * @exception JSONModelInvalidDataException thrown when the input data does not include all required keys
 */
-(id)initFromURLWithString:(NSString*)urlString;

-(id)initFromURLWithString:(NSString *)urlString completion:(JSONModelBlock)completeBlock;

@end