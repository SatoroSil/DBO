-- �Ұ�Ų �� ��° Ű�� ����


Scene(1, "1452301")
--[
	-- �Ұ�Ų ��� "�̷� �Ͷ��� �༮��!?������ ���࿭���� �¿����״� ��ø� ��ٷ�!"
	Action( "say" )
	--[
		Param( "tblidx", 3233 )
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
			Param( "wps index", 28013 )
			Param( "event id", 470 )
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