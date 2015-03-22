encounters = 0

function isScreenOn()
	return Poke:GetLightLevel() > 200
end

function hunt()
	Poke:Push("X", 200)
	Poke:Push("A", 200)
	Poke:Sleep(1600)
	Poke:Push("A", 200)
	Poke:Push("Down", 200)
	Poke:Push("A", 200)
	Poke:Push("A", 200)
	check()
end

function check()
	--Wait to see if screen has turned back on
	Poke:Sleep(20500)
	Poke:Println(tostring(Poke:GetLightLevel()))
	encounters = encounters + 1
	Poke:Println("Encounters: " .. tostring(encounters))
	
	--If screen is on, then return to hunting
	if isScreenOn() then
		Poke:Push("Left", 200)
		Poke:Push("Right", 200)
		Poke:Push("A", 200)
		Poke:Sleep(7700)
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