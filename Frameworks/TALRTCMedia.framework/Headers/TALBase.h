#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TALCameraPosition) {
    TALCameraPositionBack  = 1,
    TALCameraPositionFront = 2,
};

/*
 ___________________________________________________________________________________________
 | Standard | Resolution | Aspect Ratio |        framerate(fps) bitrate(bps)               |
 -------------------------------------------------------------------------------------------
 |   720p   |  1280x720  |    16:9      | 15fps 1130000bps; 30fps 1710000bps               |
 ----------------------------------------                                                  |
 |          |  720x1280  |     9:16     |                                                  |
 -------------------------------------------------------------------------------------------
 |   480p   |   640x480  |     4:3      |  10fps 400000; 15fps 500000bps; 30fps 750000bps  |
 ----------------------------------------                                                  |
 |          |   480x640  |     3:4      |                                                  |
 -------------------------------------------------------------------------------------------
 | Wide 360p|   640x360  |    16:9      |  15fps 400000; 30fps 600000bps                   |
 ----------------------------------------                                                  |
 |          |   360x640  |     9:16     |                                                  |
 -------------------------------------------------------------------------------------------
 |   360p   |   480x360  |     4:3      |  15fps 320000; 30fps 490000bps                   |
 ----------------------------------------                                                  |
 |          |   360x480  |     3:4      |                                                  |
 -------------------------------------------------------------------------------------------
 |   288p   |   352x288  |     4:3      |  15fps 264000bps                                 |
 ----------------------------------------                                                  |
 |          |   288x352  |     3:4      |                                                  |
 -------------------------------------------------------------------------------------------
 |   240p   |   320x240  |     4:3      |  15fps 200000bps                                 |
 ----------------------------------------                                                  |
 |          |   240x320  |     3:4      |                                                  |
 -------------------------------------------------------------------------------------------
 |   180p   |   320x180  |    16:9      |  15fps 140000bps                                 |
 ----------------------------------------                                                  |
 |          |   180x320  |     9:16     |                                                  |
 -------------------------------------------------------------------------------------------
 |    90p   |   160x90   |    16:9      |  15fps 70000bps                                  |
 ----------------------------------------                                                  |
 |          |    90x160  |     9:16     |                                                  |
 -------------------------------------------------------------------------------------------
 
 ___________________________________________________________________________________________
 |  Custom  | Resolution | Aspect Ratio |        framerate(fps) bitrate(bps)               |
 -------------------------------------------------------------------------------------------
 |          |   720x720  |     1:1      |  15fps 910000bps; 30fps 1380000bps               |
 -------------------------------------------------------------------------------------------
 |          |   480x480  |     1:1      |  15fps 400000bps; 30fps 600000bps                |
 -------------------------------------------------------------------------------------------
 |          |   360x360  |     1:1      |  15fps 260000bps; 30fps 400000bps                |
 -------------------------------------------------------------------------------------------
 |          |   288x288  |     1:1      |  15fps 180000bps                                 |
 -------------------------------------------------------------------------------------------
 |          |   180x180  |     1:1      |  15fps 100000bps                                 |
 -------------------------------------------------------------------------------------------
 |          |    90x90   |     1:1      |  15fps 50000bps                                  |
 -------------------------------------------------------------------------------------------
 */
typedef NS_ENUM(NSInteger, TALVideoResolution) {
    TALVideoResolution720p = 0,
    TALVideoResolution480p,
    TALVideoResolutionWide360p,
    TALVideoResolution360p,
    TALVideoResolution288p,
    TALVideoResolution240p,
    TALVideoResolution180p,
    TALVideoResolution90p,
    
    // Square
    TALVideoResolution720x720,
    TALVideoResolution480x480,
    TALVideoResolution360x360,
    TALVideoResolution288x288,
    TALVideoResolution180x180,
    TALVideoResolution90x90,
};

typedef NS_ENUM(NSInteger, TALVideoOrientationMode) {
    TALVideoOrientationModeAdaptative = 0,
    TALVideoOrientationModeFixedLandscape,
    TALVideoOrientationModeFixedFixedPortrait,
};

typedef NS_ENUM(NSInteger, TALVideoRotate) {
    TALVideoRotate0 = 0,
    TALVideoRotate90,
    TALVideoRotate180,
    TALVideoRotate270,
};

typedef NS_ENUM(NSInteger, TALViewContentMode) {
    TALViewContentModeScaleAspectFit = 0, //填黑边保持比例
    TALViewContentModeScaleAspectCutFill, //裁剪图像填充
    TALViewContentModeScaleAspectFill, //不保持图像比例，拉伸图像填充
};

typedef NS_ENUM(NSInteger, TALVideoMirrorMode) {
    TALVideoMirrorModeNone = 0,         // 预览不启用镜像，推流不启用镜像
    TALVideoMirrorModeOnlyPreview,      // 预览启用镜像，推流不启用镜像
    TALVideoMirrorModeOnlyRemote,       // 预览不启用镜像，推流启用镜像
    TALVideoMirrorModePreviewAndRemote, // 预览启用镜像，推流启用镜像
};

typedef NS_ENUM(NSInteger, TALRecordType) {
    TALRecordTypeMP4 = 0,
    TALRecordTypeFLV,
};
