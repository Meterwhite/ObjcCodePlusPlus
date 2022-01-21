Pod::Spec.new do |s|
  s.name         = "ObjcCodepp"
  s.version      = "1.4"
  s.summary      = 'objc code++.'
  s.homepage     = 'https://github.com/Meterwhite/ObjcCodePlusPlus'
  s.license      = 'MIT'
  s.author       = { "meterwhite" => "quxingyi@outlook.com" }
  s.requires_arc = true
  s.source       = { :git => "https://github.com/Meterwhite/ObjcCodePlusPlus.git", :tag => s.version}
  s.source_files  = 'Code++ for ObjcC/Code++/**/*.{h,m}'
end
