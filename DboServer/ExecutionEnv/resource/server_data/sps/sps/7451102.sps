--- The SPS battery used in the past          ---
--- 05 May 13, 2011 Currently unused ---
Scene(1, "6013")
--[


		 -- 3. 6013���� ���� WPS Event ID ����
		Action( "wait" )
		--[
			Param("event type", "wps")
			Param( "event id", 601301)
		--]
		End()

		-- 4. ����� ���� ���
		 Action( "char condition" )
		 --[
				Param( "attack disallow", 1)   
		 --]
		 End()
		 
		 
		-- 5. ������ ����� �̾߱� �ϱ�
--		Action( "say" )
		--[
--			  ���� �������� ���ο� �������ΰ� ���� 
			--Param( "tblidx", 1 )           
		--]     
--		End()

		Action( "wait" )
		--[
			   Param( "time", 2)
		--]
		End()

--		Action( "say" )
		--[
--			 ��? ���� ����̾��ݾ�
			--Param( "tblidx", 1 )           
		--]     
--		End()

		Action( "wait" )
		--[
			   Param( "time", 2)
		--]
		End()

--	       Action( "say" )
		--[
--			 "��� ���� �Ƿ��� �ѹ� ����?"
			--Param( "tblidx", 1 )           
		--]     
--		End()

		Action( "wait" )
		--[
			   Param( "time", 2)
		--]
		End()

		-- 6. ��ȭ ���� WPS�� EventId ����
		Action( "send sps event" )
		--[
				Param( "event type", "wps" ) 
				Param( "event id", 601302 )
		--]
		End()

		-- 4. ����� ���� ���
		 Action( "char condition" )
		 --[
				Param( "attack disallow", 0)   
		 --]
		 End()

--]
End()



