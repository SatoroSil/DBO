-- UD4 ù��° �� ���� �濡�� ������ ������(21251101) ���ĳ���


Scene(1, "21251101")
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
			Param( "wps index", 29007 )
			Param( "event id", 666 )
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