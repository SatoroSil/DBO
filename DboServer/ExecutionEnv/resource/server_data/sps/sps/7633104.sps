Scene( 1, "7633104" )
--[
	Action( "char condition" )
	--[
		Param( "invincible", 0 )
		Param( "ui disable", 1 )
	--]
	End()

	-- �� �� �� ���ڵ��� ���� ������ ���ھ�.
	Action( "say" )
	--[
		Param( "tblidx", 3272 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()

	Action( "point move" )
	--[
		Param( "loc x", 290.32 )
		Param( "loc y", -96.64 )
		Param( "loc z", -3588.70 )
		Param( "dir x", 1.00 )
		Param( "dir z", 0.05 )
		Param( "run mode", 0 )
	--]
	End()

	Action( "send event to wps" )
	--[
		Param( "wps index", 2633 )
		Param( "event id", 531 )
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()
