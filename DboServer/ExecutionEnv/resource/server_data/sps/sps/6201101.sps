------------------------------------------------------
--
-- �տ���
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------

Scene( 1, "TLQ1 �Ҷ��� �Ҹ��� �������� ������ �տ���" )

--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 881.15)
		Param( "loc z", -1002.00)
		Param( "dir x", -0.69)
		Param( "dir z", -0.72)
		Param( "run mode", 1 )
    --]
    End()

	Action( "sps end" )
	--[
	--]
	End()
	
End()

------------------------------------------------------


Scene( 2, "TLQ 1 �������� �������� ���� �޷����� �տ���" )

--Wait until receive event from WPS
	Action( "wait" )
	--[
		Param("event type", "wps")
		Param( "event id", 16080)
	--]
	End()

--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 935.20)
		Param( "loc z", -1015.47)
		Param( "run mode", 1 )
    --]
    End()

--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 1006.41)
		Param( "loc z", -1021.92)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 1060.69)
		Param( "loc z", -1076.03)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 1094.81)
		Param( "loc z", -1084.32)
		Param( "dir x", 0.62)
		Param( "dir z", 0.79)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 1097.83)
		Param( "loc z", -1079.25)
		Param( "dir x", 0.62)
		Param( "dir z", 0.79)
		Param( "run mode", 1 )
    --]
    End()
	
--Send event to WPS
	Action( "send sps event" )
	--[
		Param( "event type", "wps" ) 
		Param( "event id", 16090 )
	--]
	End()

--���
	Action( "wait" )
	--[
		Param("event type", "wps")
		Param( "event id", 16120)
	--]
	End()
	
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 1060.69)
		Param( "loc z", -1076.03)
		Param( "run mode", 1 )
    --]
    End()
	
--�տ��� �̵� ���� �˸�
	Action( "send sps event" )
	--[
		Param( "event type", "wps" ) 
		Param( "event id", 16160 )
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()

End()


------------------------------------------------------


Scene( 3, "TLQ 1 �Ʊ� ������ �޾Ƽ� ���� �տ���" )

--User�� ������ �ް� ���� 16180�� �´�
	Action( "wait" )
	--[
		Param("event type", "ts")
		Param( "event id", 16180)
	--]
	End()
	
--�̵�
	Action( "point move" )
	--[
		Param( "loc x", 915.77)
		Param( "loc y", 9.57)
		Param( "loc z", -960.61)
		Param( "run mode", 1 )
	--]
	End()
	

	Action( "send sps event" )
	--[
		Param( "event type", "wps" ) 
		Param( "event id", 16250 )
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()

End()


------------------------------------------------------


Scene( 4, "TLQ 1 ������ ���� �տ���" )

--���
	Action( "wait" )
	--[
		Param("event type", "ts")
		Param( "event id", 16280)
	--]
	End()

--�̵�
	Action( "point move" )
	--[
		Param( "loc x", 915.77)
		Param( "loc y", 9.57)
		Param( "loc z", -960.61)
		Param( "run mode", 1 )
	--]
	End()



	Action( "leave" )
	--[    
	--]
	End()


	
End()


------------------------------------------------------
