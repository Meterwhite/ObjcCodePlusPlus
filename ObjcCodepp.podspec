Pod::Spec.new do |s|
  s.name         = "ObjcCodepp"
  s.version      = "1.0"
  s.summary      = 'objc code++.'
  s.homepage     = 'https://github.com/meterwhite/ObjcCodepp'
  s.license      = 'MIT'
  s.author       = { "meterwhite" => "quxingyi@outlook.com" }
  s.requires_arc = true
  s.source       = { :git => "https://github.com/meterwhite/ObjcCodepp.git", :tag => s.version}
  s.source_files  = 'Code++/**/*.{h,m}'
end
