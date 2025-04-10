Scene( 1, "34007" )
--[
--�����
	Action( "char condition" )
	--[
		Param( "invincible", 0 )
		Param( "ui disable", 1 )
	--]
	End()

--��� �Ϸ� ��ٸ�
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 34007 )
			Param( "event id", 891 )
		--]
		End()
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()			

--��û�� ���� ���		
	Action( "say" )
	--[
		Param( "tblidx", 3356 )
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()
		
	Action( "say" )
	--[
		Param( "tblidx", 3357 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()

--��������
	Action( "direct play" )
	--[
		Param( "tblidx", 60061 )
	--]
	End()

-- �������� �̺�Ʈ ��		
	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id", 892 )
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
	
	-- �������� ���� �ϴ±�...
	Action( "say" )
	--[
		Param( "tblidx", 3378 )
	--]
	End()

	-- ������������ �̵�
	Action( "point move" )
	--[
		Param( "loc x", -399.25 )
		Param( "loc y", 144.86 )
		Param( "loc z", 719.4 )
		Param( "dir x", -0.91 )
		Param( "dir z", -0.41 )
		Param( "run mode", 1 )
	--]
	End()
	
	-- ���θ� ����(�׷��� ���� rotate�۵����� ����)
	Action( "rotate" )
	--[
		Param( "dir x", -0.91 )
		Param( "dir z", -0.41 )
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 1 )
	--]
	End()
	
	-- ���Ͷ�! ���� ���ε��. 
	Action( "say" )
	--[
		Param( "tblidx", 3369 )
	--]
	End()
	
	-- wps�� ���� npc spawn��Ű��� �˷���. (wps������ ����� ������ �� npc spawn��Ŵ)
	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id", 987 )
	--]
	End()
	
	-- ������� ���μ�ȯ �ִϸ��̼� ���
	Action( "direct play" )
	--[
		Param( "tblidx", 60063 )
	--]
	End()
	
	-- wps���� ���� npc ��� spawn��ų �� ���� ���
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 34007 )
			Param( "event id", 988 )
		--]
		End()
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 1 )
	--]
	End()

	-- ���� �������� �� ��¦ �̵�
	Action( "point move" )
	--[
		Param( "loc x", -399.47 )
		Param( "loc y", 144.86 )
		Param( "loc z", 718.12 )
		Param( "dir x", -0.59 )
		Param( "dir z", -0.81 )
		Param( "run mode", 0 )
	--]
	End()
	
	-- ���ҷӱ�! ������. �ּ��̵��.
	Action( "say" )
	--[
		Param( "tblidx", 3370 )
	--]
	End()
	
	-- wps�� �˷���
	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id", 989 )
	--]
	End()
	
	-- ����� �������
	Action( "direct play" )
	--[
		Param( "tblidx", 60064 )
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



Scene( 3, "34007" )
--[
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()
	
	Action( "say" )
	--[
		Param( "tblidx", 3379 )
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", -399.25 )
		Param( "loc y", 144.86 )
		Param( "loc z", 719.4 )
		Param( "dir x", -0.91 )
		Param( "dir z", -0.41 )
		Param( "run mode", 1 )
	--]
	End()
	
	-- ���θ� ����(�׷��� ���� rotate�۵����� ����)
	Action( "rotate" )
	--[
		Param( "dir x", -1 )
		Param( "dir z", 0.07 )
	--]
	End()
	
	Action( "wait" )
	--[
		Param( "time", 1 )
	--]
	End()
	
	-- ���ε����� ���� ����ϴ� ���� �������� �˾ƶ�.
	Action( "say" )
	--[
		Param( "tblidx", 3371 )
	--]
	End()
	
	-- ���� ��������(���� ����) �� ��¦ �̵�
	Action( "point move" )
	--[
		Param( "loc x", -398.01 )
		Param( "loc y", 144.86 )
		Param( "loc z", 718.66 )
		Param( "dir x", 0.41 )
		Param( "dir z", -0.91 )
		Param( "run mode", 0 )
	--]
	End()
	
	-- wps�� �˷���
	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id", 990 )
	--]
	End()
	
	-- ����� �������
	Action( "direct play" )
	--[
		Param( "tblidx", 60064 )
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




Scene( 4, "34007" )
--[
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()

	-- ���� ¥������ �ϴ±�.
	Action( "say" )
	--[
		Param( "tblidx", 3380 )
	--]
	End()

	Action( "point move" )
	--[
		Param( "loc x", -399.25 )
		Param( "loc y", 144.86 )
		Param( "loc z", 719.4 )
		Param( "dir x", -0.91 )
		Param( "dir z", -0.41 )
		Param( "run mode", 1 )
	--]
	End()
	
	-- ���θ� ����(�׷��� ���� rotate�۵����� ����)
	Action( "rotate" )
	--[
		Param( "dir x", -0.91 )
		Param( "dir z", -0.41 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 1 )
	--]
	End()
	
	-- ������ ���� ���� ���ָ�.
	Action( "say" )
	--[
		Param( "tblidx", 3372 )
	--]
	End()
	
	-- ���� ����(��ι���)���� �� ��¦ �̵�
	Action( "point move" )
	--[
		Param( "loc x", -400.53 )
		Param( "loc y", 144.86 )
		Param( "loc z", 718.96 )
		Param( "dir x", -1 )
		Param( "dir z", 0.07 )
		Param( "run mode", 0 )
	--]
	End()
	
	-- wps�� �˷���
	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id", 991 )
	--]
	End()
	
	-- ����� �������
	Action( "direct play" )
	--[
		Param( "tblidx", 60064 )
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