-- DWC1
-- �Գ��ε� spawn�Ǿ� ��� ��

Scene( 1, "70001" )
--[
	-- npc ui �ȳ������� ��
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()
	
	-- ��� ���ִ� ������ ���±���~
	Action( "say" )
	--[
		Param( "tblidx", 3320 )
	--]
	End()
	
	-- User���� ���ĳ���
	Action( "point move" )
	--[
		Param( "loc x", 1691.8 )
		Param( "loc y", -109.38 )
		Param( "loc z", -1506.27 )
		Param( "dir x", 0.48 )
		Param( "dir z", 0.87 )
		Param( "run mode", 1 )
	--]
	End()
	
	-- �Գ��ε� ���ĳ����� �Ϸ�
	Action( "send event to wps" )
	--[
		Param( "wps index", 70001 )
		Param( "event id", 622 )
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()
--]
End()



-- DWC1 �뼭 �ް� �Գ��ε� �����
Scene( 3, "70002" )
--[
	-- npc ui �ȳ������� ��
--	�Ʒ� code�� ������ WPS�� �ߴܵǴµ�? Ȯ�� �ʿ�.
--	Action( "char condition" )
--	--[
--		Param( "ui disable", 1 )
--	--]
--	End()
	
	-- ����. ����. ������ ���ϰ� �첲.
	Action( "say" )
	--[
		Param( "tblidx", 3321 )
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", 1777.07 )
		Param( "loc y", -108.22 )
		Param( "loc z", -1491.11 )
		Param( "dir x", -0.96 )
		Param( "dir z", 0.28 )
		Param( "run mode", 1 )
	--]
	End()
	
	Action( "leave" )
	--[
	
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()
--]
End()


-- DWC1 �뼭 �ȹް� �Գ��ε� ������
Scene( 4, "70001" )
--[
	-- npc ui �ȳ������� ��
--	�Ʒ� code�� ������ WPS�� �ߴܵǴµ�? Ȯ�� �ʿ�.
--	Action( "char condition" )
--	--[
--		Param( "ui disable", 1 )
--	--]
--	End()

	-- ���� ���... �ΰ� ����!! �������״�!!
	Action( "say" )
	--[
		Param( "tblidx", 3322 )
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", 1777.07 )
		Param( "loc y", -108.22 )
		Param( "loc z", -1491.11 )
		Param( "dir x", -0.96 )
		Param( "dir z", 0.28 )
		Param( "run mode", 1 )
	--]
	End()
	
	Action( "leave" )
	--[
	
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()
--]
End()

