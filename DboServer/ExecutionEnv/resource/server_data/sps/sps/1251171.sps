Scene(1, "UD6 Ű�������� NPC ������ �����ϻ� 2")
--[
	
	--34012 WPS���� �̺�Ʈ�� �޴´�.
	Action("wait")
	--[
		Condition("recv event from wps")
		--[
			Param("wps index", 34012)
			Param("event id", 976)
		--]
		End()
	--]
	End()
	
	--NPC�� UI�� �����ش�.
	Action("char condition")
	--[
		Param("ui disable", 1)
	--]
	End()
	
	Action("sps end")
	--[
	
	--]
	End()

--]
End()