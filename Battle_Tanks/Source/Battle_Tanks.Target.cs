// Property of Pineapple Softworks

using UnrealBuildTool;
using System.Collections.Generic;

public class Battle_TanksTarget : TargetRules
{
	public Battle_TanksTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Battle_Tanks" } );
	}
}
