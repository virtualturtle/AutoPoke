encounters = 0
light = Poke:GetLightLevel()
Poke:Println("light:" .. tostring(light))

function isScreenOn()
	return Poke:GetLightLevel() > light - 30
end


function hunt()
	Poke:Push("X", 160)
	Poke:Push("A", 160)
	Poke:Sleep(1600)
	Poke:Push("A", 160)
	Poke:Push("Down", 160)
	Poke:Push("A", 160)
	Poke:Push("A", 160)
	check()
end

function check()
	--Wait to see if screen has turned back on
	Poke:Sleep(19700)
	Poke:Println(tostring(Poke:GetLightLevel()))
	encounters = encounters + 1
	Poke:Println("Encounters: " .. tostring(encounters))
	
	--If screen is on, then return to hunting
	if isScreenOn() then
		Poke:Push("Down", 200)
		Poke:Push("Right", 200)
		Poke:Push("A", 160)
		Poke:Sleep(6100)
	else
		--If screen is still off, then we have a shiny
		Poke:Println("Found a Shiny!!!")
		while true do
			--Loop FOREVER!!!!
		end
	end
end




while true do
	hunt()
end