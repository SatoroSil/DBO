------------------------------------------------------
--
-- ���ݷ�
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene(1, "TMQ 2 ���ݷ�" )

--���ݷ� �����ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 12080)
	--]
	End()
	
--���ݷ� ������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", -1141.71)
		Param( "loc z", 853.07)
		Param( "run mode", 1 )
    --]
    End()
	
--���ݷ� ���� ����
	Action( "direct play" )
	--[
		Param( "tblidx", 50042)
	--]     
	End()

	Action( "leave" )
	--[    
	--]
	End()

End()

	
------------------------------------------------------


Scene(2, "TMQ 2 ���ݷ�" )

--�̵���ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 12261)
	--]
	End()

	Action( "point move" )
	--[
		Param( "loc x", 775.87)
		Param( "loc z", -23.43)
		Param( "run mode", 1 )
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", 831.19)
		Param( "loc z", -127.91)
		Param( "run mode", 1 )
	--]
	End()
	
--���ݷ� �����1 �θ���
	Action( "send sps event" )
	--[
		Param( "event type", "tqs" ) 
		Param( "event id", 12270 )
	--]
	End()

	Action( "point move" )
	--[
		Param( "loc x", 853.33)
		Param( "loc z", -147.67)
		Param( "run mode", 1 )
	--]
	End()
	
--�̵� Ȯ���ϱ�
	Action( "send sps event" )
	--[
		Param( "event type", "tqs" ) 
		Param( "event id", 12271 )
	--]
	End()
	
--���ݷ� �̵���Ű��
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param("event id", 12280)
	--]
	End()

	Action( "point move" )
	--[
		Param( "loc x", 895.92)
		Param( "loc z", -164.60)
		Param( "run mode", 1 )
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", 924.84)
		Param( "loc z", -199.58)
		Param( "run mode", 1 )
	--]
	End()
	
--���ݷ� �����2 �θ���
	Action( "send sps event" )
	--[
		Param( "event type", "tqs" ) 
		Param( "event id", 12290 )
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", 936.04)
		Param( "loc z", -217.32)
		Param( "run mode", 1 )
	--]
	End()
	
--�̵� Ȯ���ϱ�
	Action( "send sps event" )
	--[
		Param( "event type", "tqs" ) 
		Param( "event id", 12291 )
	--]
	End()
	
--�����2 ����, ���ݷ� �̵���Ű��
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 12300)
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", 987.45)
		Param( "loc z", -343.88)
		Param( "run mode", 1 )
	--]
	End()

	Action( "point move" )
	--[
		Param( "loc x", 976.68)
		Param( "loc z", -365.78)
		Param( "run mode", 1 )
	--]
	End()

	
--���� �����1 �θ���
	Action( "send sps event" )
	--[
		Param( "event type", "tqs" ) 
		Param( "event id", 12310 )
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", 962.58)
		Param( "loc z", -385.83)
		Param( "run mode", 1 )
	--]
	End()
	
--���ݷ� �����ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 12370)
	--]
	End()
	
--���ݷ� ������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", 957.25)
		Param( "loc z", -392.71)
		Param( "run mode", 1 )
    --]
    End()
	
--���ݷ� ���� ����
	Action( "direct play" )
	--[
		Param( "tblidx", 50042)
	--]     
	End()
	
	Action( "leave" )
	--[    
	--]
	End()  

End()


------------------------------------------------------


Scene(4, "TMQ 2 ���ݷ�" )

	Action( "direct play" )
	--[
		Param( "tblidx", 50040)
	--]     
	End()

	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 24100)
	--]
	End()
	
	Action( "leave" )
	--[    
	--]
	End()

End()


------------------------------------------------------