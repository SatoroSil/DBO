------------------------------------------------------
--
-- Ʈ��ũ��
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene( 1, "TMQ1" )

-- Ʈ��ũ�� ����Ʈ�� �̵� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 11040)
	--]
	End()

--Ʈ��ũ�� ����Ʈ�� �̵�
    Action( "point move" )
	--[
		Param( "loc x", 796.00)
		Param( "loc z", -801.57)
		Param( "run mode", 1 )
	--]
	End()
	
	Action( "point move" )
	--[
		Param( "loc x", 794.57)
		Param( "loc z", -792.68)
		Param( "run mode", 1 )
	--]
	End()
	
--Ʈ��ũ�� �̵��Ϸ� �˸�
	Action( "send sps event" )
	--[
		Param( "event type", "tqs" ) 
		Param( "event id", 11050 )
	--]
	End()
	
-- Ʈ��ũ�� ���� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 11100)
	--]
	End()
	
--Ʈ��ũ�� ������ ���� �̵�
	Action( "point move" )
    --[
		Param( "loc x", 788.92)
		Param( "loc z", -793.53)
		Param( "run mode", 1 )
    --]
	End()
	
-- Ʈ��ũ�� ���� ����
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