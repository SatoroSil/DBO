
Scene( 1, "34007" )
--[
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()
	
	-- ���� ������ ���� �����ָ�...
	Action( "say" )
	--[
		Param( "tblidx", 3381 )
	--]
	End()

	-- ���� ����� �߾����� �̵�
	Action( "point move" )
	--[
		Param( "loc x", -402.78 )
		Param( "loc y", 144.86 )
		Param( "loc z", 704.6 )
		Param( "dir x", -0.71 )
		Param( "dir z", -0.71 )
		Param( "run mode", 1 )
	--]
	End()

	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id", 992 )
	--]
	End()
	
	-- �� ���� ����� �����! �����!
	Action( "say" )
	--[
		Param( "tblidx", 3382 )
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()
--]
End()


Scene( 2, "34007" )
--[
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()
	
	-- ��������... �Ӹ���... ������...
	Action( "say" )
	--[
		Param( "tblidx", 3383 )
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 10 )
	--]
	End()

	-- ��ٷ���... �� ����� �ν��ָ�...
	Action( "say" )
	--[
		Param( "tblidx", 3384 )
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 10 )
	--]
	End()
	
	-- ����ü ��ũ�� ���� ���� ����...
	Action( "say" )
	--[
		Param( "tblidx", 3385 )
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 10 )
	--]
	End()
	
--]
End()