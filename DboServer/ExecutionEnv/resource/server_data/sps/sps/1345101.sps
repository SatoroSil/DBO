Scene(1, "1880")
--[
	Action( "char condition")
	--[
		Param( "ui disable", 1 )
	--]
	End()
	
	Action( "say" )
	--[
		Param( "tblidx", 3047 )
	--]     
	End()
	
	Action( "wait" )
	--[
		Param( "time", 2 )    
	--]
	End()

	--�ؽ�Ʈ �߰�
	Action( "say" )
	--[
		Param( "tblidx", 3048 )           
	--]
	End()	

	Action( "path move" )
	--[
		Param( "tblidx", 13451011 )
		Param( "run mode", 1 )
	--]
	End()

	--WPS�� EventId ���� (�� ���� ��û) A
	Action( "send event to wps" )
	--[
		Param( "wps index", 1880 )
		Param( "event id", 378 )
	--]
	End()

	--�� ���� Ȯ�� ��ȣ ��� B
	Action( "wait" )
	--[
		Condition("recv event from wps")
		--[
			Param("wps index", 1880 )
			Param("event id", 379 )
		--]
		End()
	--]
	End()

	--�ؽ�Ʈ (���������� �߰�! ���������� �߰�!)
	Action( "say")
	--[
		Param( "tblidx", 3049 )           
	--]     
	End()
	
	--SPS�� ���� ������ ��� (���� ��� ��ȣ) C
	Action( "wait" )
	--[
		Condition("recv event from wps")
		--[
			Param("wps index", 1880 )
			Param("event id", 380 )
		--]
		End()
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3050 )
	--]
	End()
	
	Action( "path move" )
	--[
		Param("tblidx", 13451012)
		Param("run mode", 1 )
	--]
	End()

	--�������� �κ�

	-- �ؽ�Ʈ (��. �ֿ�����. �߰�. ���. �缳��.)
	Action( "say" )
	--[
		Param( "tblidx", 3122 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 1 )    
	--]
	End()

	Action( "path move" )
	--[
		Param("tblidx", 13451014)
		Param("run mode", 1 )
	--]
	End()

	-- WPS�� EventId ���� (�� ���� ��û) D
	Action( "send event to wps" )
	--[
		Param( "wps index", 1880) 
		Param( "event id", 381 )
	--]
	End()

	--�� ���� Ȯ�� ��ȣ ��� E
	Action( "wait" )
	--[
		Condition("recv event from wps")
		--[
			Param("wps index", 1880 )
			Param("event id", 382 )
		--]
		End()
	--]
	End()

	-- �ؽ�Ʈ (����������. �߰�! ����ǰ!  �ı��ؾ�. �Ѵ�. ����ǰ!)
	Action( "say" )
	--[
		Param( "tblidx", 3051)
	--]     
	End()
	
	-- SPS�� ���� ������ ��� (���� ��� ��ȣ) F
	Action( "wait" )
	--[
		Condition("recv event from wps")
		--[
			Param("wps index", 1880)
			Param("event id", 383)
		--]
		End()
	--]
	End()
	
	-- �ؽ�Ʈ �߰�
	Action( "say" )
	--[
		Param( "tblidx", 3052 )           
	--]     
	End()
	
	Action( "wait" )
	--[
		Param( "time", 2 )    
	--]
	End()

	--������Ʈ ����	(�����ȣ) G
	Action( "send event to wps" )
	--[
		Param( "wps index", 1880 ) 
		Param( "event id", 384 )
	--]
	End()

	Action( "path move" )
	--[
		Param( "tblidx", 13451013 )
		Param( "run mode", 1 )
	--]
	End()

	--�ؽ�Ʈ (����. ������. ����. �⵿ �Ұ�. �⵿ �Ұ�. �ӹ�. ����. �Ҵ�, �������. ��ȯ.)
	Action( "say" )
	--[
		Param( "tblidx", 3123 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 3 )    
	--]
	End()

	--SPS���� ��ȣ H
	Action( "send event to wps" )
	--[
		Param( "wps index", 1880 )
		Param( "event id", 385 )
	--]
	End()

	Action( "char condition")
	--[
		Param( "ui disable", 0 )
	--]
	End()

	Action( "leave" )
	--[
	--]
	End()
--�� �������� PC��� �־��� ��
--]
End()
