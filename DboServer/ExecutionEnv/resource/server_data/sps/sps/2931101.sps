------------------------------------------------------
--
-- �տ���
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene( 1, "TMQ 4 stage1" )

--���
	Action( "wait" )
	--[
		Param( "time", 5 )
	--]
	End()

--������ ���
	Action( "sitdown" )
	--[
		Param( "sitdown", "true")
	--]
	End()

--���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14053)
	--]
	End()
	
--�Ͼ
	Action( "sitdown" )
	--[
		Param( "sitdown", "false")
	--]
	End()
	
--���� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14080)
	--]
	End()

--������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", 847.89)
		Param( "loc z", -877.22)
		Param( "run mode", 1 )
    --]
    End()
	
--���� ����
	Action( "direct play" )
	--[
		Param( "tblidx", 50049)
	--]     
	End()
	
	Action( "leave" )
	--[    
	--]
	End()  
	
End()
	
------------------------------------------------------


Scene( 2, "TMQ 4 stage2" )

--�̵� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14450)
	--]
	End()

--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 656.34)
		Param( "loc z", -415.91)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 656.60)
		Param( "loc z", -475.87)
        Param( "dir x", -0.28)
        Param( "dir z", -0.96)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14462)
	--]
	End()
	
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 636.74)
		Param( "loc z", -528.14)
        Param( "dir x", 0.03)
        Param( "dir z", -1.00)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14464)
	--]
	End()

--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 635.05)
		Param( "loc z", -533.76)
        Param( "dir x", -0.985)
        Param( "dir z", 0.174)
		Param( "run mode", 1 )
    --]
    End()
	
--���
	Action( "wait" )
	--[
		Param( "time", 1 )
	--]
	End()
	
--������ ���
	Action( "sitdown" )
	--[
		Param( "sitdown", "true")
	--]
	End()
	
--���̴��
	Action( "wait" )
	--[
		Param("event type", "ts")
		Param( "event id", 11020)
	--]
	End()
	
End()


------------------------------------------------------