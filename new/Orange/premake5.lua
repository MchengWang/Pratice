include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Orange"
	architecture "x86_64"
	startproject "Orangefruit"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Orange/vendor/Box2D"
	include "Orange/vendor/GLFW"
	include "Orange/vendor/Glad"
	include "Orange/vendor/msdf-atlas-gen"
	include "Orange/vendor/imgui"
	include "Orange/vendor/yaml-cpp"
group ""

group "Core"
	include "Orange"
	include "Orange-scriptCore"
group ""

group "Tools"
	include "Orangefruit"
group ""

group "Misc"
	include "Sandbox"
group ""
