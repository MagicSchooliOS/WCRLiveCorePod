Pod::Spec.new do |s|

  s.name         = "WCRLiveCore"
  s.version      = "1.2.56"
  s.summary      = "WCRLiveCore库提供了音视频的推拉流能力与信道能力并封装了大班课拉流播放器WCRLivePlayer"

  s.description  = "WCRLiveCore库提供了音视频推拉流、在线课件、在线涂鸦、课堂管理与信道能力并封装了大班课拉流播放器WCRLivePlayer"

  s.homepage     = "https://github.com/MagicSchooliOS/WCRLiveCorePod"
  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author       = { "weclassroom" => "weclassroom@icloud.com" }
  
  s.platform     = :ios, "8.0"

  s.source       = { :git => "git@github.com:MagicSchooliOS/WCRLiveCorePod.git", :tag => "#{s.version}"  }

  s.vendored_frameworks = ["Frameworks/*.framework"]

end
