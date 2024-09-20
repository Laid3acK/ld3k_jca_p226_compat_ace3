class CfgPatches
{
    class ld3k_jca_p226_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_P226",
            "Weapons_F_JCA_P226_Accessories",
            "Weapons_F_P226_Pistols_P226"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    // JCA Bullets inherited from vanilla class B_9x21_Ball. To avoid all conflict with other mod, all JCA bullets with JCA as prefixe.
    // class B_9x21_Ball: BulletBase from official BI tool All-in-one Config Arma3 2.17.152041 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class BulletBase;
    /*class B_9x21_Ball: BulletBase
    {
        hit=5;
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_9mm";
        cost=100;
        typicalSpeed=380;
        airFriction=-0.0016;
        caliber=1.2;
        deflecting=25;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        airLock=1;
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=1;
        audibleFire=30;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
    };
    class B_9x21_Ball_Tracer_Green: B_9x21_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=0;
    };
    class B_9x21_Ball_Tracer_Red: B_9x21_Ball_Tracer_Green
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class B_9x21_Ball_Tracer_Yellow: B_9x21_Ball_Tracer_Green
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Yellow";
    };
    class JCA_B_9x21_Ball_Tracer_IR: B_9x21_Ball_Tracer_Green // JCA default config
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        nvgOnly=1;
    };
    class ACE_9x19_Ball: B_9x21_Ball // ACE3 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L505
    {
        airFriction=-0.00201185;
        ACE_caliber=9.017;
        ACE_bulletLength=15.494;
        ACE_bulletMass=8.0352;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619};
        ACE_ballisticCoefficients[]={0.165};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={340,370,400};
        ACE_barrelLengths[]={101.6,127.0,228.6};
    };*/
    class JCA_B_9x19_Ball_P226_FMJ: BulletBase // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ https://www.sigsauer.com/blog/sig-sauer-introduces-m17-9mm-p-ammunition
    {
        ACE_caliber=9.03; // 0.356" CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        ACE_bulletLength=14.859; // 0.585" https://www.sigsauer.com/9mm-p-124gr-elite-ball-m17-fmj-box-50.html
        ACE_bulletMass=8.035; // 124gr
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10. Muzzle velocity shift 0 at 70°F (21°C), -1m/s at 15°C
        ACE_ballisticCoefficients[]={0.209}; // recalculated ICAO G1 BC based on Sig Sauer 2024 datas https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=57
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_barrelLengths[]={101.6,127.0,228.6}; // default ACE3 4", 5", 9" barrel lengths
        ACE_muzzleVelocities[]={366,396,426}; // at 21°C (70°F: Temp vs MV chart zero), 365m/s (1198fps) 4" barrel - 377m/s (1237fps) 4.4" (112mm) barrel at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_P226 initSpeed
        hit=4.8; // B_9x21_Ball 5, 571 Joules
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_9mm";
        cost=100;
        typicalSpeed=377; // JCA_15Rnd_9x19_P226_FMJ_Mag and JCA_15Rnd_9x19_P226_JHP_Mag initSpeed
        airFriction=-0.00152792; // B_9x21_Ball -0.0016, airFrictionAnalysis.txt in docs folder
        caliber=1.2;
        deflecting=25;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        airLock=1;
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=0; // B_9x21_Ball 1
        audibleFire=30;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
    };
    class JCA_B_9x19_Ball_P226_JHP: JCA_B_9x19_Ball_P226_FMJ // M17 Sig Sauer NATO 9x19mm +P 124gr V-Crown https://www.sigsauer.com/blog/sig-sauer-introduces-m17-9mm-p-ammunition
    {
        ACE_caliber=9.03; // 0.356" CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        ACE_bulletLength=14.859; // 0.585" https://www.sigsauer.com/9mm-p-124gr-elite-ball-m17-fmj-box-50.html
        ACE_bulletMass=8.035; // 124gr
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10. Muzzle velocity shift 0 at 70°F (21°C), -1m/s at 15°C
        ACE_ballisticCoefficients[]={0.179}; // recalculated ICAO G1 BC based on Sig Sauer 2024 datas https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=57
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_barrelLengths[]={101.6,127.0,228.6}; // default ACE3 4", 5", 9" barrel lengths
        ACE_muzzleVelocities[]={366,396,426}; // at 21°C (70°F: Temp vs MV chart zero), 365m/s (1198fps) 4" barrel - 377m/s (1237fps) 4.4" (112mm) barrel at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_P226 initSpeed
        hit=8; // B_9x21_Ball 5, 571 Joules
        airFriction=-0.00178511; // airFrictionAnalysis.txt in docs folder
        caliber=0.72; // B_9x21_Ball 1.2
    };
    class JCA_B_9x19_Ball_P226_SUB: JCA_B_9x19_Ball_P226_FMJ // M1153 Sig Sauer 9x19mm 147gr Jacketed Hollow Point JHP https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=57
    {
        ACE_caliber=9.03; // 0.356" CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        ACE_bulletLength=14.859; // 0.585" 9mm 147gr Elite V-Crown JHP https://www.sigsauer.com/9mm-147gr-elite-v-crown-jhp-20ct.html
        ACE_bulletMass=9.525; // 147gr
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10. Muzzle velocity shift 0 at 70°F (21°C), -1m/s at 15°C
        ACE_ballisticCoefficients[]={0.204}; // recalculated ICAO G1 BC based on Sig Sauer 2024 datas https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=57
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_barrelLengths[]={101.6,127.0,228.6}; // default ACE3 4", 5", 9" barrel lengths
        ACE_muzzleVelocities[]={301,331,361}; // at 21°C (70°F: Temp vs MV chart zero), 300m/s (985fps) 4" barrel - 312m/s (1024fps) 4.4" (112mm) barrel at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_P226 initSpeed
        hit=7.2; // B_9x21_Ball 5, 464 Joules
        typicalSpeed=312; // JCA_15Rnd_9x19_P226_SUB_Mag initSpeed
        airFriction=-0.00109026; // airFrictionAnalysis.txt in docs folder
        caliber=0.72; // B_9x21_Ball 1.2
        visibleFire=1; // Subsonic, B_127x54_Ball, BulletBase 3
        audibleFire=5; // Subsonic, B_127x54_Ball, B_9x21_Ball 30
    };
    class JCA_B_9x19_Ball_P226_Tracer_Green: JCA_B_9x19_Ball_P226_FMJ
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_9x19_Ball_P226_Tracer_Red: JCA_B_9x19_Ball_P226_FMJ
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class JCA_B_9x19_Ball_P226_Tracer_Yellow: JCA_B_9x19_Ball_P226_FMJ
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Yellow";
    };
    class JCA_B_9x19_Ball_P226_Tracer_IR: JCA_B_9x19_Ball_P226_FMJ
    {
        nvgOnly=1;
    };
};
class CfgMagazines
{
    class CA_Magazine;
    // class 16Rnd_9x21_Mag: 30Rnd_9x21_Mag from official BI tool All-in-one Config Arma3 2.17.152041 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    /*class 30Rnd_9x21_Mag: CA_Magazine
    {
        author="$STR_A3_Bohemia_Interactive";
        scope=2;
        displayName="$STR_A3_CfgMagazines_30Rnd_9x21_Mag0";
        picture="\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
        ammo="B_9x21_Ball";
        count=30;
        mass=10;
        initSpeed=370;
        tracersEvery=0;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_9x21_Mag1";
    };
    class 16Rnd_9x21_Mag: 30Rnd_9x21_Mag
    {
        author="$STR_A3_Bohemia_Interactive";
        displayName="$STR_A3_CfgMagazines_16Rnd_9x21_Mag0";
        picture="\A3\weapons_f\data\ui\M_16Rnd_9x21_CA.paa";
        type=16;
        count=16;
        descriptionShort="$STR_A3_CfgMagazines_16Rnd_9x21_Mag1";
        mass=6;
        initSpeed=410;
    };*/
    class JCA_15Rnd_9x19_P226_FMJ_Mag: CA_Magazine // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        scope=2;
        displayName="9 mm 15rnd P226 FMJ Mag";
        picture="\weapons_f_JCA_P226\MagazineProxies\data\UI\Icon_15Rnd_9x21_P226_Mag_CA.paa";
        ammo="JCA_B_9x19_Ball_P226_FMJ";
        type=16; // 16Rnd_9x21_Mag
        count=15;
        mass=5.7; // 76g + 15x190g, JCA 6
        initSpeed=377; // according to ACE_muzzleVelocities 4.4" barrel (112mm) ICAO conditions (15°C, 1013.25hPa, 0%), JCA 410
        tracersEvery=0;
        descriptionShort="Caliber: 9x19 mm<br />Rounds: 15<br />Used in: P226";
        displaynameshort="FMJ";
    };
    class JCA_15Rnd_9x19_P226_JHP_Mag: JCA_15Rnd_9x19_P226_FMJ_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Jacketed Hollow Point JHP
    {
        author="Grave";
        displayName="9 mm 15rnd P226 JHP Mag";
        ammo="JCA_B_9x19_Ball_P226_JHP";
        displaynameshort="JHP";
    };
    class JCA_15Rnd_9x19_P226_SUB_Mag: JCA_15Rnd_9x19_P226_FMJ_Mag // M1153 Sig Sauer 9x19mm 147gr Jacketed Hollow Point JHP
    {
        author="Grave";
        displayName="9 mm 15rnd P226 Subsonic Mag";
        ammo="JCA_B_9x19_Ball_P226_SUB";
        initSpeed=312; // according to ACE_muzzleVelocities 4.4" barrel (112mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Subsonic";
    };
    class JCA_15Rnd_9x19_P226_Red_Mag: JCA_15Rnd_9x19_P226_FMJ_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 15rnd P226 Tracer (Red) Mag";
        ammo="JCA_B_9x19_Ball_P226_Tracer_Red";
        displaynameshort="Tracer";
        tracersEvery=1;
    };
    class JCA_15Rnd_9x19_P226_Green_Mag: JCA_15Rnd_9x19_P226_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 15rnd P226 Tracer (Green) Mag";
        ammo="JCA_B_9x19_Ball_P226_Tracer_Green";
    };
    class JCA_15Rnd_9x19_P226_Yellow_Mag: JCA_15Rnd_9x19_P226_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 15rnd P226 Tracer (Yellow) Mag";
        ammo="JCA_B_9x19_Ball_P226_Tracer_Yellow";
    };
    class JCA_15Rnd_9x19_P226_IR_Mag: JCA_15Rnd_9x19_P226_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 15rnd P226 Tracer (IR) Mag";
        ammo="JCA_B_9x19_Ball_P226_Tracer_IR";
        displaynameshort="Tracer IR";
    };
};
class CfgMagazineWells
{
    /*class JCA_P226_9x21 // JCA default config
    {
        JCA_Magazines[]=
        {
            "JCA_15Rnd_9x21_P226_Mag",
            "JCA_15Rnd_9x21_P226_Red_Mag",
            "JCA_15Rnd_9x21_P226_Green_Mag",
            "JCA_15Rnd_9x21_P226_Yellow_Mag",
            "JCA_15Rnd_9x21_P226_IR_Mag"
        };
    };*/
    class JCA_P226_9x19 // Weapon initSpeed -1 with ACE_barrelLength 112mm (4.4"), 377m/s - 312m/s at ICAO standart conditions (15°C, 1013.25 hPa, 0%) according to JCA_15Rnd_9x19_P226_FMJ_Mag, JCA_15Rnd_9x19_P226_JHP_Mag and JCA_15Rnd_9x19_P226_SUB_Mag initSpeed
    {
        JCA_Magazines[]=
        {
            "JCA_15Rnd_9x19_P226_FMJ_Mag",
            "JCA_15Rnd_9x19_P226_JHP_Mag",
            "JCA_15Rnd_9x19_P226_SUB_Mag",
            "JCA_15Rnd_9x19_P226_Red_Mag",
            "JCA_15Rnd_9x19_P226_Green_Mag",
            "JCA_15Rnd_9x19_P226_Yellow_Mag",
            "JCA_15Rnd_9x19_P226_IR_Mag"
        };
    };
};
class Mode_SemiAuto;
class CfgWeapons
{
    class ItemCore;
    class InventoryMuzzleItem_Base_F;
    class Pistol;
    class Pistol_Base_F: Pistol
    {
        class WeaponSlotsInfo;
    };
    class JCA_hgun_P226_base_F: Pistol_Base_F // U.S. Navy SEALs P226 MK25 https://www.sigsauer.com/p226-mk25-full-size.html
    {
        ACE_barrelLength=112; // 4.4" P226 https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=15
        ACE_barrelTwist=250; // CIP twist https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        initSpeed=-1; // 377m/s - 312m/s, 112mm barrel, according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 380
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_15Rnd_9x19_P226_FMJ_Mag",
            "JCA_15Rnd_9x19_P226_JHP_Mag",
            "JCA_15Rnd_9x19_P226_SUB_Mag",
            "JCA_15Rnd_9x19_P226_Red_Mag",
            "JCA_15Rnd_9x19_P226_Green_Mag",
            "JCA_15Rnd_9x19_P226_Yellow_Mag",
            "JCA_15Rnd_9x19_P226_IR_Mag"
        };
        magazineWell[]=
        {
            "JCA_P226_9x19"
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.001061; // 6.49 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0037 (12.72 MOA)
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=21.3; // 964g with magazine https://www.sigsauer.com/p226-mk25-full-size.html, JCA 27
        };
    };
    class JCA_optic_MPO_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=1.40109; // from ACE3 checkScopes.sqf
    };
    class JCA_muzzle_snds_tactical_base: ItemCore
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class JCA_muzzle_snds_9MM_tactical_black: JCA_muzzle_snds_tactical_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=6; // muzzle_snds_L, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // muzzle_snds_L 1
                recoilProneCoef=0.95; // muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
    class JCA_muzzle_snds_9MM_tactical_sand: JCA_muzzle_snds_tactical_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=6; // muzzle_snds_L, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // muzzle_snds_L 1
                recoilProneCoef=0.95; // muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
    class JCA_muzzle_snds_9MM_tactical_olive: JCA_muzzle_snds_tactical_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=6; // muzzle_snds_L, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // muzzle_snds_L 1
                recoilProneCoef=0.95; // muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
    // from official BI tool All-in-one Config Arma3 2.17.152041 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class muzzle_snds_H: ItemCore // Sound Suppressor 6.5mm
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class muzzle_snds_L: muzzle_snds_H // Sound Suppressor 9mm
    {
        class ItemInfo: ItemInfo
        {
            // mass=6;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // muzzle_snds_L 1
                recoilProneCoef=0.95; // muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.1;
    };
};