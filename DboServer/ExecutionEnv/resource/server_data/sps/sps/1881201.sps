-- ������ ���� ����
-- spawn���� �߾����� �̵�

Scene( 1, "1881201" )
--[
	-- ���� spawn�� �ణ �����ʿ� ġ���� �ִ�.
	-- �߾����� �̵�
	Action( "point move" )
	--[
		Param( "loc x", 237.20 )
		Param( "loc y", 17.57 )
		Param( "loc z", 301.46 )
		Param( "dir x", -0.64 )
		Param( "dir z", 0.77 )
		Param( "run mode", 1 )
	--]
	End()

	-- ���� ���� ���ýñ��� ���
	-- ���� �߻��ϸ� �̺�Ʈ ���ƿ��� ���ķδ� ���� spawn�������� ����ϰ� ��
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 32004 )
			Param( "event id", 593 )
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