--- The SPS battery used in the past         ---
--- 05 May 13, 2011 Currently unused ---
Scene(1, "6004")
--[
	    -- 16. SPS�� ���� ������ ��� 
		Action( "wait" )
		--[
			Param("event type", "wps")
			Param( "event id", 600405)
		--]
		End()	
		

		 Action( "char condition" )
		 --[
				Param( "attack disallow", 1)   
		 --]
		 End()
		 
		 
		-- 17. ���������� ��ȭ(���� �̰��� ������ ���� ��ġ��. �� ����̸� ��ġ�϶�. ).
--		Action( "say" )
		--[
--			  "���� �̰��� ������ ���� ��ġ��. "
			--Param( "tblidx", 1 )           
		--]     
--		End()

		Action( "wait" )
		--[
			   Param( "time", 2)
		--]
		End()

--     	Action( "say" )
		--[
--			  "�� ����̸� ��ġ�϶�.
			--Param( "tblidx", 1 )           
		--]     
--		End()

		Action( "wait" )
		--[
			   Param( "time", 2)
		--]
		End()
		
		Action( "char condition" )
		 --[
				Param( "attack disallow", 0)   
		 --]
		 End()
		 
		 
		 
		-- 19. WPS�� EventId ����
		Action( "send sps event" )
		--[
				Param( "event type", "wps" ) 
				Param( "event id", 600406 )
		--]
		End()
--]
End()