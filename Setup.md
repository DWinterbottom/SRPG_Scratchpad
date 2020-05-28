#I had a bunch of trouble getting my tools to play nice, so here's my rundown.
I'm not going to make a lot of effort keeping this up to date.

Make sure scons and cl/link are accessible from the command line.
I installed the Visual Studio Community Edition, you can get just the build tools. If they don't add to the path for whatever reason there's a command prompt in the Visual Studio folder that you can run the rest through, or a batch file to add them at `path\to\visual\studio\Community\VC\Auxiliary\Build\vcvars64.bat`

The godot-cpp repo has a bunch of information its readme.
Check godot-cpp to make sure it's got its contents.
If it's broken `git submodule update` will hopefully fix it.
If that doesn't work you might need to use `git submodule add https://github.com/GodotNativeTools/godot-cpp.git`
Hopefully you'll also get the `godot_headers` submodule within that.

Export api json file. I put it in here.
`your/godot/executable.exe (or just godot) --gdnative-generate-json-api api.json`

Build godot-cpp
You can get scons using `pip install scons`, or if your environment is being dodgy `python -m pip install scons`
Had a bit of trouble with the default bits when I built for windows and didn't specify bits.
`scons platform=windows bits=64 generate_bindings=yes use_custom_api_file=yes custom_api_file=../api.json`
Add `-j4` to use 4 (for example) threads.
If scons is being difficult perhaps `python -m scons` will play nicer.

Go back to the main folder and build.
You'll probably have to create the `bin` folder inside the SRPG_Scratchpad project folder.
`scons platform=windows`