-- �Ұ�Ų ù ��° Ű�� ����


Scene(1, "1452201")
--[
	-- �Ұ�Ų ��� "������~ ���� ��������~ ������~ "
	Action( "say" )
	--[
		Param( "tblidx", 3232 )
	--]
	End()

	Action( "direct play" )
	--[
		Param( "tblidx", 60051 )
	--]
	End()

	-- ����� ���� ���� �̺�Ʈ�� ��ٸ�
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 28012 )
			Param( "event id", 469 )
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