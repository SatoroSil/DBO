-- DWC1
-- 1381101: ȣ�� �θ���. �ǰ��ְ�, LP�� ����.

-- �θ��� escort
Scene( 1, "70001" )
--[
	-- npc ui �ȳ������� ��
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()

	-- ȣ�� �θ��� escort �ϴ� sps ���� �Ϸ�� �� Ȯ��
	Action( "send event to wps" )
	--[
		Param( "wps index", 70001 )
		Param( "event id", 634 )
	--]
	End()

	-- �̷��� �ϸ� npc�� target follow�ϴ� �߿� say�� �� �ִٰ� �������� �׷��µ� �۵����� ����
	-- Ȯ���غ���
	Action( "function" )
	--[
		Condition( "child" )
		--[
			-- �θ����� ���� ������
			Action( "wait" )
			--[
				Condition( "recv event from wps" )
				--[
					Param( "wps index", 70003 )
					Param( "event id", 834 )
				--]
				End()
			--]
			End()
			
			-- ����~! ������ �����!!
			Action( "say" )
			--[
				Param( "tblidx", 3351 )
			--]
			End()
			
			Action( "wait" )
			--[
				Param( "time", 3 )
			--]
			End()
		--]
		End()
		
		Condition( "child" )
		--[
			-- �θ����� ���� ������
			Action( "wait" )
			--[
				Condition( "recv event from wps" )
				--[
					Param( "wps index", 70004 )
					Param( "event id", 835 )
				--]
				End()
			--]
			End()
			
			-- ���� ��! �� ����!
			Action( "say" )
			--[
				Param( "tblidx", 3352 )
			--]
			End()
			
			Action( "wait" )
			--[
				Param( "time", 3 )
			--]
			End()
		--]
		End()

		-- escort ���
		Action( "escort" )
		--[
			Param( "type", "target follow" )
			Param( "dest x", 0 )
			Param( "dest z", 0 )
			Param( "radius", 20 )
			Param( "event id", 633 )
		--]
		End()

	--]
	End()



	Action( "sps end" )
	--[
	--]
	End()
--]
End()

-- �θ��� �Ҹ�����
Scene( 2, "70001" )
--[
	-- ����~! ������ ��Ÿ����~!
	Action( "say" )
	--[
		Param( "tblidx", 3350 )
	--]
	End()

	-- 3�� ��ٷȴٰ�
	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()

	-- ����~! ������ ��Ÿ����~! �ѹ� �� ���ϰ�
	Action( "say" )
	--[
		Param( "tblidx", 3350 )
	--]
	End()

	-- sps ����
	Action( "sps end" )
	--[
	--]
	End()
--]
End()