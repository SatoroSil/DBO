-- DWC1
-- �տ��� �θ��� ��Ʈ���� spawn�Ǿ� �̵���

Scene( 1, "70001" )
--[
	-- npc ui �ȳ������� ��
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()

	-- ��� �������� ���� �Ⱥ��̳�...
	Action( "say" )
	--[
		Param( "tblidx", 3323 )
	--]
	End()

	-- �տ����� user ��ó�� �̵�
	Action( "point move" )
	--[
		Param( "loc x", 1603.29 )
		Param( "loc y", -84.32 )
		Param( "loc z", -1694.83 )
		Param( "dir x", 0.00 )
		Param( "dir z", 1.00 )
		Param( "run mode", 1 )
	--]
	End()

	-- �տ��� �̵� �Ϸ� �˷���
	Action( "send event to wps" )
	--[
		Param( "wps index", 70003 )
		Param( "event id", 637 )
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()