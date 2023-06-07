{
  "targets": [
    {
      "target_name": "caldev",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/_caldev.cpp",
        "./src/asyncWorker.cc",
        "./src/index.cpp"
      ],
      "include_dirs": [
        "../dll",
        "<!@(node -p \"require('node-addon-api').include\")",
      ],
    "ldflags": [
    "-Wl,-rpath,'$$ORIGIN'"
   
],
 "libraries": [
        #  "C:/Users/bruno/Documents/Dev/kayros/testBorlandDll/Win64/Debug/CalDevLib.dll"
      ],
      #  'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
       'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
    }
  ]
}