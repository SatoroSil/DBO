-- DWC1
-- 1381102: ��� �θ���. �ǰݾ���, LP�� ����.

-- DWC1 �θ��� ���Ϻ��� User �߰��ϰ� �̵�
Scene( 1, "70001" )
--[
	-- npc ui �ȳ������� ��
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()
	
	-- User���� ���ĳ���
	Action( "point move" )
	--[
		Param( "loc x", 1696.01 )
		Param( "loc y", -110.44 )
		Param( "loc z", -1499.46 )
		Param( "dir x", 0.8 )
		Param( "dir z", 0.6 )
		Param( "run mode", 1 )
	--]
	End()
	
	Action( "send event to wps" )
	--[
		Param( "wps index", 70001 )
		Param( "event id", 619 )
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()
--]
End()

