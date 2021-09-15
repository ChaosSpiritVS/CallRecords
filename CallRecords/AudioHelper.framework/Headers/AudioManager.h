//
//  AudioManager.h
//  AudioRecords
//
//  Created by 陈芳 on 2021/9/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AudioManager;
@class AVPlayer;
@class AVAudioRecorder;

@protocol AudioManagerDelegate <NSObject>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>> AVAudioRecorder <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/// 结束录音
/// @param recorder 录音器
/// @param flag 录制成功或失败标识
- (void)audioManager:(AudioManager *)audioManager finishRecordsWithRecorder:(AVAudioRecorder *)recorder successfully:(BOOL)flag;

/// 录音编码错误
/// @param recorder 录音器
/// @param error 录音编码错误
- (void)audioManager:(AudioManager *)audioManager encodeErrorDidOccurWithRecorder:(AVAudioRecorder *)recorder error:(NSError *)error;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>> AVPlayer <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/// 开始播放
/// @param player 播放器
- (void)audioManager:(AudioManager *)audioManager startPlayWithPlayer:(AVPlayer *)player;

/// 播放结束
/// @param player 播放器
- (void)audioManager:(AudioManager *)audioManager finishPlayWithPlayer:(AVPlayer *)player;

/// 更新缓冲进度
/// @param bufferProgress 缓冲进度
- (void)audioManager:(AudioManager *)audioManager updateBufferProgress:(NSTimeInterval)bufferProgress;

/// 更新播放进度
/// @param player 播放器
- (void)audioManager:(AudioManager *)audioManager updateProgressWithPlayer:(AVPlayer *)player;

/// 播放rate更新
/// @param avPlayer 播放器
/// @param rate 速率
- (void)audioManager:(AudioManager *)audioManager audioPlayer:(AVPlayer *)avPlayer changeRate:(float)rate;

/// currentItem更新
/// @param avPlayer 播放器
- (void)audioManager:(AudioManager *)audioManager changeCurrentItem:(AVPlayer *)avPlayer;

/// 播放失败
/// @param player 播放器
- (void)audioManager:(AudioManager *)audioManager playFailedWithPlayer:(AVPlayer *)player;

/// 资源未知
/// @param player 播放器
- (void)audioManager:(AudioManager *)audioManager unKnownWithPlayer:(AVPlayer *)player;


@end

@interface AudioManager : NSObject

@property (nonatomic, weak) id<AudioManagerDelegate> delegate;

+ (instancetype)sharedInstance;

/// 开始录音
- (void)startRecords;
/// 暂停录音
- (void)recPause;
/// 停止录音
- (void)recStop;

/// 播放录音
/// @param playItemURL 播放URL
- (void)playAudioWithURL:(NSURL *)playItemURL;
/// 录音暂停后继续播放
- (void)play;
/// 录音播放中让其暂停
- (void)pause;

@end

NS_ASSUME_NONNULL_END
