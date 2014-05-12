//
//  HUSemiCircleChart.h
//  HUChart
//
//  Created by hugo on 11/19/13.
//  Copyright (c) 2013 AugoLab. All rights reserved.
//

/**********************************************************************************************************************/
/*************************************************
// @修订者：宋飞翔
// @修改说明：原版本里只能画半圆，通过修改在头文件里添加宏定义开关，可以设定为圆形、半圆形百分比显示
//          同时修改了所画园的原点，改为所指定矩形fram的中心（相对坐标）
 *********************************************************************/
/**********************************************************************************************************************/


#import <Foundation/Foundation.h>

#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

//在这里可以设定打开哪个开关
//例如，如果画半圆则如下定义即可
//#define SEMICIRCLE  1

#ifdef SEMICIRCLE  //半圆
#define ANGLE M_PI
#else
#define ANGLE (2*M_PI)  //全圆
#endif



typedef enum showTextType
{
    DONT_SHOW_PORTION,
    SHOW_PORTION_VALUE,
    SHOW_PORTION_TEXT
} ShowTextType;

@interface HUSemiCircleChart : UIView

@property (nonatomic) NSMutableArray *data;             // Data for presenting chart, contain HUChartEntry
@property (nonatomic) NSMutableArray *colors;           // Colour for each element, contain UIColor
@property (nonatomic) NSString *title;                  // Chart title
@property (nonatomic) ShowTextType showPortionTextType; // Show text/value/nothing for each portion. Default=SHOW_PORTION_TEXT
@property (assign) BOOL showChartTitle;                 // Show chart title (Default:YES)

@end
