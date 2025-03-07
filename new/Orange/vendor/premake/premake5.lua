project "Premake"
    kind "Utility"

    targetdir ("%{wks.location}/bin/" .. outdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-obj/" .. outdir .. "/%{prj.name}")

    files
    {
        "%{wks.location}/**premake5.lua"
    }

    postbuildmessage "Regenerating project files with premake5!"
    postbuildcommands
    {
        "%{prj.location}bin/premake5 %{_ACTION} --file=\"%{wks.location}premake5.lua\""
    }