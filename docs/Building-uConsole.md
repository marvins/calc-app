# Building Geospatial Toolbox for ClockworkPi uConsole

The uConsole is a tricky-ish setup due to it's default image having some older dependencies. 

**Note:** I did a bunch of extra stuff here, as I wanted the uConsole to actually compile the release for my <u>PicoCalc</u>. 

---
##  Building Desktop Variant for uConsole

### Step 1 : Clone repositories

I usually create a fresh workspace

```bash
mkdir workspace
pushd workspace
```

Next, clone the repos

```bash
git clone git@github.com:marvins/calc-app.git
git clone git@github.com:Terminus-Geospatial/terminus-setup.git
```

---

#  Building Pico Software

## Step 1:  Setup Pico SDK

Download CMake version 3.13 or later, 

