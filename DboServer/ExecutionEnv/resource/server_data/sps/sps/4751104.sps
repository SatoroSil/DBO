-- 2011�� 05�� 13�� ���� ��� ���� ---
-- ������ ��ȣ��
Scene( 1, "1" )
	
	Action( "escort" )
	--[    
		Param( "type", "under escort")      
		
	--]
	End()

	Action( "char condition" )
	--[
		Param( "ui disable", 1)      
	--]
	End()

--	Action( "say" )
	--[
--		 "�� ��� �غ���."
	--]     
--	End()


	Action( "wait" )
	--[
		Param( "time", 10 )
	--]
	End()

	Action( "path move" )
	--[
		Param( "tblidx", 603101)
		Param( "run mode", 1 )
	--]
	End()

--	Action( "say" )
	--[
--		 "�� �ձ��� �賭�ϴٱ�" 
	--]     
--	End()

	Action( "wait" )
	--[
		Param( "time", 4 )
	--]
	End()

	Action( "path move" )
	--[
		Param( "tblidx", 603102)
		Param( "run mode", 1 )
	--]
	End()

--	Action( "say" )
	--[
--		 "2�� �н� ����"
	--]     
--	End()

	Action( "wait" )
	--[
		Param( "time", 4 )
	--]
	End()

	Action( "path move" )
	--[
		Param( "tblidx", 603103)
		Param( "run mode", 1 )
	--]
	End()

--	Action( "say" )
	--[
--		"���� ����
	--]     
--	End()

	Action( "send sps event" )
	--[
		Param( "event type", "escort") 
		Param( "trigger type", "quest") 
		Param( "event id", 603201)      
	--]
	End()

	Action( "char condition" )
	--[
		Param( "ui disable", 0)      
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 10 )
	--]
	End()

	Action( "leave" )
	--[    
	--]
	End()

End()