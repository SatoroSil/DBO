-- UD4 ù��° �� ���� �濡�� ������ ������(7112225) ���ĳ���


Scene(1, "7112225")
--[
	-- ��� "ħ���ڴ�! ħ���ڰ� ���Դ�!"
	Action( "say" )
	--[
		Param( "tblidx", 3024 )
	--]
	End()

	Action( "path move" )
	--[
		Param( "tblidx", 8 )
		Param( "run mode", 1 )
	--]
	End()

	-- ��� "ħ���ڴ�! ħ���ڰ� ���Դ�!"
	Action( "say" )
	--[
		Param( "tblidx", 3024 )
	--]
	End()

	-- ����� ���� ���� �̺�Ʈ�� ��ٸ�
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 28007 )
			Param( "event id", 468 )
		--]
		End()
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()
--]
End()