
Scene(1, "2553" )
--[
        Action( "char condition" )
        --[
                Param( "ui disable", 1 )
        --]
        End()

	-- �ش� ������ �������ڸ��� �ַ��� �̲������̴�
	-- y�� ���� ���� ���̰��̹Ƿ� �ٽ� �����ؼ� �������ֽʶ��
        Action( "point move" )
        --[
                Param( "loc x", -2395.759 )
                Param( "loc y", -140.957 )
                Param( "loc z", -4509.709 )
                Param( "run mode", 1 )
        --]
        End()
        
        Action( "target fix attack" )
        --[
                Param( "obj type", "npc" )
                Param( "bot tblidx", 3213107 )
                Param( "scan range", 50 )
                Param( "end type", "percent target lp" )
                Param( "end value", 0 )
        --]
        End()
        
        Action( "sps end" )
        --[
        
        --]
        End()
--]
End()