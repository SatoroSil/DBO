------------------------------------------------------
--
-- ����糪��
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene( 1, "TMQ 4 ����糪��" )

--���� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14510)
	--]
	End()

--���� ����
	Action( "direct play" )
	--[
		Param( "tblidx", 50044)
	--]     
	End()
	
	Action( "leave" )
	--[    
	--]
	End()  
	
End()


------------------------------------------------------


Scene( 2, "TMQ 4 ����糪��" )

--���� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14570)
	--]
	End()

--������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", 477.66)
		Param( "loc z", -465.97)
		Param( "run mode", 1 )
    --]
    End()
	
--���� ����
	Action( "direct play" )
	--[
		Param( "tblidx", 50044)
	--]     
	End()
	
	Action( "leave" )
	--[    
	--]
	End()  
	
End()


------------------------------------------------------