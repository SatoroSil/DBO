--- ���� ������ ���� SPS          ---
--- 2011�� 05�� 13�� ���� ��� ���� ---
Scene(1, "6013")
--[
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
		Param( "attack disallow", 1 )
		Param( "invincible", 1 )
	--]
	End()

	Action( "ai bit flag" )
	--[
		Param( "attack type", "timid" )
	--]
	End()

	Action( "wait" )
	--[
		Param( "event type", "wps" )
		Param( "event id", 601301 )
	--]
	End()

--	Action( "say" )
	--[
--		"���ο� �������ΰ� ����"
	--]
--	End()

	Action( "wait" )
	--[
		Param( "time", 6 )
	--]
	End()

--	Action( "say" )
	--[
--		 "��� �Ƿ��� �ѹ� ����?" 
	--]
--	End()

	Action( "char condition" )
	--[
		Param( "attack disallow", 0 )
		Param( "invincible", 0 )
	--]
	End()

	Action( "ai bit flag" )
	--[
		Param( "attack type", "offensive" )
	--]
	End()

	Action( "sps end" )
	--[
	
	--]
	End()
--]
End()

Scene(2, "6013")
--[
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
		Param( "attack disallow", 1 )
		Param( "invincible", 1 )
	--]
	End()

	Action( "ai bit flag" )
	--[
		Param( "attack type", "timid" )
	--]
	End()

	Action( "wait" )
	--[
		Param( "event type", "wps" )
		Param( "event id", 601302 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()

--	Action( "say" )
	--[
--		"��? ���� ������ݾ�,"
	--]
--	End()

	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()

	Action( "char condition" )
	--[
		Param( "attack disallow", 0 )
		Param( "invincible", 0 )
	--]
	End()

	Action( "ai bit flag" )
	--[
		Param( "attack type", "offensive" )
	--]
	End()

	Action( "sps end" )
	--[
	
	--]
	End()
--]
End()
