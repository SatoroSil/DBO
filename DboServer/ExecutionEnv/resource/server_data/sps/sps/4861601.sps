Scene( 1, "34007" )
--[
--������ �����

--��� ��ٸ�
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 34007 )
			Param( "event id", 881 )
		--]
		End()
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3373 )
	--]
	End()		

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()

-- ������Ʈ ��������� �̺�Ʈ ��
	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id",  886 )
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()