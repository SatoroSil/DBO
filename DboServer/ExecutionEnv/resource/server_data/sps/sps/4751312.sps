Scene( 1, "4751312" )
--[
	Action( "char condition" )
	--[
		Param( "invincible", 0 )
		Param( "ui disable", 1 )
	--]
	End()

	-- ���� ��� ����ĭ ��Ʈ�� �ϼ��ϰ� ���ƿ��ڽ��ϴ�
	Action( "say" )
	--[
		Param( "tblidx", 3274 )
	--]
	End()

	-- ��߽�ȣ ���
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 2574 )
			Param( "event id", 530 )
		--]
		End()
	--]
	End()

	Action( "point move" )
	--[
		Param( "loc x", -1206.01 )
		Param( "loc y", -135.18 )
		Param( "loc z", -3848.10 )
		Param( "dir x", -0.87 )
		Param( "dir z", 0.48 )
		Param( "run mode", 1 )
	--]
	End()

	Action( "send event to wps" )
	--[
		Param( "wps index", 2574 )
		Param( "event id", 527 )
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()
