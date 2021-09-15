//
//  CallMainViewController.m
//  CallRecords
//
//  Created by 陈芳 on 2021/9/14.
//

#import "CallMainViewController.h"
#import <AudioHelper/AudioHelper.h>

@interface CallMainViewController ()

@property (nonatomic, strong) UIButton * recordBtn;

@end

@implementation CallMainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.view addSubview:self.recordBtn];
    
}

- (void)recordStartClick {
    
    [[AudioManager sharedInstance] startRecords];
}

-(UIButton *)recordBtn {
    if (!_recordBtn) {
        _recordBtn = [[UIButton alloc] initWithFrame:CGRectMake(self.view.center.x, self.view.center.y, 100, 100)];
        _recordBtn.backgroundColor = [UIColor greenColor];
        _recordBtn.titleLabel.text = @"开始录音";
        [_recordBtn addTarget:self action:@selector(recordStartClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _recordBtn;
}

@end
