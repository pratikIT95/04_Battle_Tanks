// Property of Pineapple Softworks

using UnrealBuildTool;
using System.Collections.Generic;

public class Battle_TanksEditorTarget : TargetRules
{
	public Battle_TanksEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Battle_Tanks" } );
	}
}
