------------------------------------------------------
--
-- ũ����
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------

	
Scene(1, "TMQ 4 stage1" )

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
		Param( "event id", 14054)
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
		Param( "event id", 14090)
	--]
	End()

--������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", 834.22)
		Param( "loc z", -878.23)
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

	
Scene(2, "TMQ 4 stage3" )
 
--�̵� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14420)
	--]
	End()

--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 755.51)
		Param( "loc z", -379.68)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 651.79)
		Param( "loc z", -376.93)
		Param( "run mode", 1 )
    --]
    End()

--�̵� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14460)
	--]
	End()

--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 664.68)
		Param( "loc z", -479.41)
        Param( "dir x", -0.75)
        Param( "dir z", -0.66)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14463)
	--]
	End()
 
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 647.00)
		Param( "loc z", -535.35)
        Param( "dir x", -1.00)
        Param( "dir z", -0.03)
		Param( "run mode", 1 )
    --]
    End()
	
--�̵� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14465)
	--]
	End()
 
--�̵�
    Action( "point move" )
    --[
		Param( "loc x", 641.51)
		Param( "loc z", -540.25)
        Param( "dir x", 0.959)
        Param( "dir z", 0.283)
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