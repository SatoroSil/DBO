Scene( 1, "34007" )
--[
--��ũ

--��� ��ٸ�
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 34007 )
			Param( "event id", 882 )
		--]
		End()
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3374 )
	--]
	End()		

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()

-- ����� ���̴� �ִϸ��̼�
	Action( "direct play" )
	--[
		Param( "tblidx", 60065 )
		Param( "event id", 884 )
		Param( "event type", "wps" )
	--]
	End()

	Action( "direct play" )
	--[
		Param( "tblidx", 60067 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3375 )
	--]
	End()		

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3376 )
	--]
	End()		

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()

-- ��� �����ٰ� �̺�Ʈ ��
	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id", 885 )
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()