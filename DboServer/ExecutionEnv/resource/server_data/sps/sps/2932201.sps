------------------------------------------------------
--
-- �տ���
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene( 1, "TMQ 3 Gohan" )

--�������� ��� ������ ���� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 13195)
	--]
	End()
	
--Ǯ������ �̵�
    Action( "point move" )
    --[
        Param( "loc x", 895.33)
        Param( "loc z", -451.78)
        Param( "dir x", 0.26)
        Param( "dir z", -0.97)
        Param( "run mode", 0 )
    --]
    End()

--�������� ����� ��� ������ ���� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 13200)
	--]
	End()
	
--����� ��ұ��� �̵�
    Action( "point move" )
    --[
        Param( "loc x", 928.46)
        Param( "loc z", -502.02)
        Param( "dir x", 0.20)
        Param( "dir z", 0.98)
        Param( "run mode", 0 )
    --]
    End()

	Action( "sps end" )
	--[
	--]
	End()
	
End()


------------------------------------------------------