boxlimit = 0
eggs = 0
hatched = 0
deposited = 0
light = Poke:GetLightLevel()
Poke:Println("light:" .. tostring(light))

function isScreenDim()
	return Poke:GetLightLevel() < light - 30
end

--If we have less than 5 eggs, Ask for one. If we get one, increase our egg counter

function askforegg()
	if eggs ~=5 then
		Poke:Sleep(200)
		Poke:Println("Asking For Egg...")
		Poke:Push("A", 160)
		Poke:Sleep(350)
		Poke:Push("A", 160)
		Poke:Sleep(350)
		Poke:Push("A", 160)
		Poke:Sleep(250)
		Poke:Push("A", 160)
		Poke:Sleep(350)
		if isScreenDim() then
			Poke:Println("Egg Available!")
			Poke:Push("A", 160)
			Poke:Sleep(250)
			Poke:Push("A", 160)
			Poke:Sleep(250)
			Poke:Push("A", 160)
			Poke:Sleep(3200)
			Poke:Push("A", 160)
			Poke:Sleep(250)
			Poke:Push("A", 160)
			eggs = eggs + 1
			Poke:Println("eggs:" .. tostring(eggs))
			else
		Poke:Println("No egg available.")
		end
	end
end
--Check if an egg has hatched.  If so, increase hatched counter

function checkMaybeHatchEgg()
	if isScreenDim() then
		Poke:Println("Egg is hatching...")
		Poke:Push("A", 160)
		Poke:Sleep(18500)
		Poke:Push("B", 160) --Configurable if you want a nickname
		Poke:Sleep(3000)
		hatched = hatched + 1
	end
end

function gatherAndHatch5()
while true do
	--Poke:Println("Start Left")
	Poke:Press("Left")
	for i = 0,3400,50 do
		Poke:Sleep(50)
		checkMaybeHatchEgg()
		if hatched == 5 then
			Poke:Release("Left")
			return
		end
	end
	Poke:Release("Left")
	--Poke:Println("End Left")
		
	--Poke:Println("Start Right")
	Poke:Press("Right")
	for i = 0,3600,50 do
		Poke:Sleep(50)
		checkMaybeHatchEgg()
		if hatched == 5 then
			Poke:Release("Right")
			return
		end
	end
	Poke:Release("Right")
	--Poke:Println("End Right")
	askforegg()
	end
end

function deposit_hatched()
  hatched = 0
  eggs = 0
  Poke:Println("Going to deposit Hatchlings...")
  Poke:Push("Right", 3700)
  Poke:Push("Y", 200)
  Poke:Push("Up", 200)
  Poke:Sleep(1000)
  Poke:Push("Left", 160)
  Poke:Sleep(100)
  Poke:Push("Left", 160)
  Poke:Sleep(100)
  Poke:Push("Left", 160)
  Poke:Sleep(100)
  Poke:Push("Left", 160)
  Poke:Sleep(100)
  Poke:Push("Left", 160)
  Poke:Sleep(100)
  Poke:Push("Left", 160)
  Poke:Sleep(100)
  Poke:Push("Up", 1000)
  Poke:Sleep(2000)
  Poke:Push("Up", 1500)
  Poke:Push("Right", 250)
  Poke:Push("Right", 250)
  Poke:Push("Up", 160)
  Poke:Push("A", 160)
  Poke:Sleep(1900)
  Poke:Push("A", 160)
  Poke:Push("A", 160)
  Poke:Push("A", 160)
  Poke:Sleep(2000)
  deposit()
  deposit()
  deposit()
  deposit()
  deposit()
  boxlimit = boxlimit + 5
  --Poke:Println("ADDED 5")
  Poke:Push("B", 150)
  Poke:Sleep(400)
  Poke:Push("B", 160)
  Poke:Sleep(700)
  Poke:Push("B", 160)
  Poke:Sleep(500)
  Poke:Push("B", 160)
  Poke:Sleep(3300)
  Poke:Push("Left", 220)
  Poke:Push("Left", 220)
  Poke:Push("Left", 220)
  Poke:Push("down", 1500)
  Poke:Sleep(2700)
  Poke:Push("down", 160)
end
function deposit()
	if boxlimit == 30 then
		Poke:Push("Right", 250)
		Poke:Push("A", 250)
		Poke:Push("A", 250)
		Poke:Sleep(500)
		Poke:Push("Right", 160)
		Poke:Sleep(500)
		Poke:Push("A", 160)
		Poke:Sleep(300)
		boxlimit = 0
		--Poke.Println("SET TO 0")
	else
		Poke:Push("Right", 250)
		Poke:Push("A", 250)
		Poke:Push("A", 250)
		Poke:Sleep(400)
		Poke:Push("A", 250)
		Poke:Sleep(400)
	end
end
function loop()	
  --Poke:Println("Start")
  --Poke:Println("Bike")
  Poke:Push("Y", 160)
  Poke:Push("Up", 120)
  Poke:Sleep(1000)
  gatherAndHatch5()
  deposit_hatched()
end

while true do
	loop()
end