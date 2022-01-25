# GAS
GAS dokumentaatio


## Käsitteet

Gameplay Ability System (GAS) – Unreal Enginen liitännäinen, jolla luodaan iskuja/kykyjä peliin.

Isku/kyky – GAS:n työkaluilla luotu hyökkäys/väistäminen/taikaisku tai jonkun muun tyyppinen pelitoiminto.

Actor – Unrealissa useasti käytetty perusluokka objekteille, joka voidaan sijoit-taa pelimaailmaan.

Demo – Minun tekemä UE4-projekti, jossa näytän GAS:in toimintoja.

Unreal Engine (UE4/UE5) – Demossa käytetty pelimoottori.

Epic Games – Yritys, joka on tehnyt Unreal Enginen.

Blueprint – Unreal Enginessä käytettävä ohjelmointitapa, jolla ohjelmoidaan C++ – kieltä selkeämmin luettavaksi.

C++ – Unreal Enginen käyttämä ohjelmointikieli.

Character-luokka – Unreal Enginen valmisluokka, josta kaikki Demon hahmot periytyy.

Attribuutti – GAS-liitännäiseen liittyviä numeroarvoja, joilla määritellään esi-merkiksi pelaajan taso.

Leveli/Taso – Pelaajalla on mahdollisuus nostaa tasoa pelatessa ja tulla näin vahvemmaksi. 

HeroCharacter(päähahmo) – Hahmo, jota pelaaja hallitsee pelissä.

GameplayEffect (efekti) – GAS:n keino muuttaa attribuuttien arvoja.

Ability System Component (ASC) – Ilman tätä hahmo ei pysty suorittamaan kykyjä tai ottaa vastaan attribuutteja.

Tag(tunniste) – Nimilista, jolla ASC voi määrittää esimerkiksi, voiko kykyä käyt-tää vai ei.


## 1 Sisältö


PRGLHPRHLRPLHRPLHLHPRLHPRHLPRLHPLHR


## 2	Mikä on Gameplay Ability System?


”Gameplay Ability System (GAS eli kykyjärjestelmä)” on Epic Gamesin luoma laajennus Unreal Engine-pelimoottorille. Se luotiin alun perin pelin Paragon-hahmojen iskujen ja kykyjen luomiseen. Paragon kuitenkaan ei ikinä päässyt julkaisupisteeseen asti, mutta siinnä käytetyt työkalut ja mallit jäivät Unreal Engine 4:n ja Unreal Engine 5:n käyttöön ilmaiseksi. Myöhemmin Epic Games hyödynsi GAS:ia pelissä Fortnite, joka oli jättimenestys (kuva 1). (Prinke 2021.)

![1200px-Fortnite_gameplay](https://user-images.githubusercontent.com/55107172/144231425-0e46546f-b08d-4bf5-bcf3-6a0246fc7d77.png)
Kuva 1. Pelin Fortnite kaikki kyvyt ja rakentaminen on tehty käyttäen GAS-liitännäistä (Wikipedia 2021).

GAS ei kuitenkaan heti tullut pelikehittäjien suosioon. Pitkään GAS ei ollut valittavissa laajennuksien joukosta ja se oli vain sisällä pelimoottorin koodissa. Pelikehittäjät eivät siis välttämättä tienneet edes sen olemassaoloa, tai sitä ei osattu hyödyntää. Myös dokumentaatio oli äärimmäisen puutteellista. Myöhemmin Epic Games kuitenkin lisäsi erillisen valinnan laajennukset valikkoon nimeltä ”Gameplay Ability System”. Siitä lähtien GAS:n käyttö on yleistynyt suuresti ja dokumentaatiota aiheesta löytyy jo paljon enemmän. (Sabre-DartStudios 2018.)

GAS on siis erittäin joustava rajapinta rakentaa RPG (roolipeli) tai MOBA (tais-teluareenamoninpeli) esiintyviä kykyjä ja ominaisuuksia. Sen avulla voi rakentaa toimintoja tai passiivisia kykyjä pelin hahmojen käytettäväksi sekä tehostei-ta, jotka voivat lisätä tai kuluttaa erilaisia ominaisuuksia näiden toimintojen seurauksena. Liitännäisellä pystyy myös säätämään helposti, milloin, miten ja missä kykyjä voi käyttää ja miten ne käyttäytyvät. GAS voi auttaa sinua suunnittelemaan, toteuttamaan ja yhdistämään tehokkaasti pelin sisäisiä kykyjä yksinkertaisesta hyppäämisestä, niin monimutkaisiin kykyihin kuin nykyaikaisissa RPG- tai MOBA-nimikkeissä on nähty. (Epic Games 2004–2021.)


## 3	GAS:n hyödyt


Useasti ohjelmoijat luovat omia tapoja luoda attribuutteja ja kyky/iskuja ominaisuuksien luomiseen. Tämä yleensä johtuu halusta luoda oma systeemi, jota on helppo lukea ja muokata, eikä tarvitse pelätä liitännäisen tuomia rajotteita. GAS kuitenkin on erittäin joustava rajoitteiden suhteen ja lähes kaikkea pystyy muokkaamaan projektin toimintojen ja tyylin mukaan.  (Epic Games 2004–2021.)

GAS:n kaikki kyvyt tukevat projektiilien ennustamista (prediction) ja kykyjen ennalleen palauttamista (rollback). Ennustaminen ja palauttaminen on enemmän monipeliominaisuuksia ja siksi niitä ei käydä läpi. Ohjelmoijan on kuitenkin tärkeä huomioida, että nämä toiminnot ovat GAS:n avulla helppo toteuttaa ja se helpottaa moninpeliohjelmointia todella paljon. (SabreDartStudios 2018.)


## 4	Iskut ja kyvyt


Ennen kuin rupeaa tekemään kykyjä ja iskuja peliin, kannattaa miettiä, mitä kyvyt ja iskut pelissä voisivat olla. Pelaajan hahmolla roolipelissä on yleensä mahdollista esimerkiksi hypätä, avata ovia, vaihdella aseita, ampua, rakentaa, lyödä miekalla, juosta eri nopeuksilla ja käyttää erilaisia rohtoja ja juomia. Kaikki nämä voisivat olla pelissä kykyjä ja itse toteuttaisin kaikki varmasti hyödyntäen GAS:ia. Hyppäämiselle tosin on olemassa jo valmis funktio Unreal Enginessä joka omiin projekteihini on soveltunut hyvin vähäisellä muokkaamisella.  

GAS:ia käyttäessä ei ole varsinaista sääntöä siihen missä sitä kannattaa hyödyntää ja missä ei, mutta yleensä, ”Tranek’s GAS (2021)”-dokumentaation mukaan "kannattaa jättää tavalliset liikkumiskäskyt ja jotkut HUD-ominaisuudet omiksi toiminnoikseen". Esimerkiksi tavaran ostaminen kaupasta ei kannata olla GAS:lla luotu kyky, vaan oma suunniteltu mekaniikkansa, jossa voi käyttää toki esimerkiksi GAS:in attribuuttia valuuttana. (Tranek 2021, 4.6.1.)


## 5	GAS-konseptit


### 5.1	Ability System Component
Ability System Component (ASC eli kykyjärjestelmäkomponentti) on “UActor-Component”, jonka kautta kaikki integraatiot GAS-järjestelmässä tapahtuvat. Tämä komponentti on perusta koko GAS:lle. Jokaisella ”Actor (toimijalla)”, joka haluaa käyttää kykyjä, hyödyntää attribuutteja ja niihin liittyviä efektejä, on oltava ASC. Ohjelmoijan kannattaa luoda ASC:sta aliluokka. (Tranek 2021, 4.1.)

Actor-luokkaan, johon on yhdistetty ASC, kutsutaan nimellä ASC:n ”OwnerActor (Omistaja-Actor)”. ASC:n fyysistä representaatio Actor-luokkaa kutsutaan nimellä ”AvatarActor (Avatar-Actor)”. Omistaja ja Avatar-Actor voivat viitata samaan luokkaan, mutta moninpelissa on suositeltavaa, että Omistaja-Actor on pelihahmon PlayerState-luokka ja Avatar-Actor on pelihahmon ”Character”-luokka. Tällä tavoin pystytään helposti hallitsemaan hahmossa olevia efektejä ja attribuutteja sen synnyttyä.
Olipa Omistaja-Actor ja Avatar-Actor erillinen tai sama luokka, pitää kummankin niiden periä C++-luokka ” IAbilitySystemInterface”. (Tranek 2021, 4.1.)

### 5.2	Gameplay Tags (Tunnisteet)
GAS:ia käyttäessä huomaa monessa tilanteessa välttävän ”Boolean”-muuttujien käyttämistä.  Boolean-muuttujalla useasti tarkistetaan, mitä kohtaa koodista pitää toteuttaa, GAS:ia käyttäessä useat toteutettavat ominaisuudet tarkastetaan tunnisteilla. Tunnisteet ovat hierarkkisia nimilistoja ”FGa-meplayTags”. Tunnisteet ovat muodossa ”Vähempi. Lapsi. Lapsenlapsi…” ja niillä on todella helppo luokitella ja kuvailla objektien tilaa. (Tranek 2021, 4.2.)

Seuraavassa kuvassa (Kuva 3) on tunniste ”Element.Fire. Burning”. Tässä ta-pauksessa kyseinen tunniste voisi tulla pelaajalle, jos hahmo osuu palavaan esineeseen. Vanhempi on ”Elementti”, lapsi on ”Tuli” ja lapsenlapsi on ”Pala-minen”. Jos hahmo osuu veteen, voisi se saada Tagin ”Elementti.Vesi. Sam-muminen”. Jos tulelle ja vedelle ei tule olemaan muita ominaisuuksia kuin pa-laminen ja sammuminen, voisi tunnisteet olla myös vain ”Element.Fire” ja ”Element.Water”.

 ![Kuva5](https://user-images.githubusercontent.com/55107172/144235336-d6cdd82b-abb4-41f9-a6ab-5cef8b55d2a3.png)
Kuva 3. Hahmolle tai asialle annetaan tällainen tunniste, kun se on tulessa.

Kun tunniste annetaan objektille, se menee säilytettäväksi objektin ASC:hen. ASC perii C++-luokan ”IGameplayTagAssetInterface”, jolloin GAS:in funktiot pääsevät käsiksi objektin omistamiin tunnisteisiin. (Tranek 2021, 4.2.)



### 5.3	Attributes
Attribuutit ovat numeroarvoja, jotka viittaavat yleisimmissä roolipeleissä ainakin hahmojen elämäpisteisiin ja manapisteisiin. Jos pelissä on pelimekaniikkoihin liittyvä numeroarvo, esimerkiksi valuutta, kannattaa aina miettiä olisiko sekin hyvä toteuttaa GAS-attribuuttina. (Tranek 2021, 4.2.)

Minun demooni voisi tulla seuraavanlaisia attribuutteja:
-	Health (elämäpisteet).
-	Mana (käytettävä iskut kuluttavat tätä).
-	Erilaisia vahinkomääritteitä (physical, fire, chaos damage).
-	Hahmon taso (nousee kun päihittää vihollisia).

Päätapa muuttaa attribuuttien arvoja on aina GAS:n ”GameplayEffect”.  (Tranek 2021, 4.3.1.)

#### 5.3.1	BaseValue ja CurrentValue
Attribuutit koostuvat kahdesta arvosta, ”BaseValue (perusarvo)” ja ”CurrentValue (nykyarvo)”. Perusarvo on alkuperäinen arvo attribuutille, joka sille on annettu, esimerkiksi elämäpisteen perusarvo voisi olla sata. Nykyarvo on alkuperäinen arvo, johon lisätään jonkin efektin seurauksena plus- tai miinusarvoinen luku. Jos perusarvo on elämäpisteissä sata, eikä pelihahmo ole vahingoittunut, on myös nykyarvo sata. Jos pelihahmo vahingoittuu, hahmo ottaa -25 vahinkoa viholliselta, jonka jälkeen perusarvo edelleen on sata, mutta nykyarvoon lisätään vahingon määrä ja nyt nykyarvo on 75, koska lisätty summa oli miinusmerkkinen. (Tranek 2021, 4.3.2.)

#### 5.3.2	Attribute set
Attribuutit luodaan ”UAttributeSet”-luokkaan, eli attribuuttikokoelmaan. Ohjel-moijan kannattaa tehdä UAttributeSet-luokasta aliluokka (kuva 4). AttributeSet luodaan Omistaja-Actorin konstruktorissa ja se automaattisesti rekisteröityy sen ASC:hen. Tämä on tehtävä hyödyntäen C++-ohjelmointikieltä. (Tranek 2021, 4.4.1.)

![Kuva1](https://user-images.githubusercontent.com/55107172/144233815-6b11a395-39d6-49b5-9e72-511e780bac9f.png)

Kuva 4. AttributeSet C++-luokasta kannattaa tehdä aliluokka.

Pelissä kaikilla hahmoilla voi olla käytössä yksi yhteinen attribuuttikokoelma tai vaihtoehtoisesti esimerkkinä vihollisilla voi olla oma ja pelaajalla oma kokoelma. Muistin kannalta tällä ei ole suurta merkitystä, mutta useampi kokoelma voi selkeyttää toimintaa editorissa.
ASC:lla voi olla käytössä useampi attribuuttikokoelma ja ohjelmoija voi itse määrän päättää. Saman luokan kokoelmaa ei kuitenkaan kannata olla kuin yksi ASC:lla. Jos saman luokan kokoelmia on useampi, ASC valitsee niistä vain yhden käyttöön satunnaisesti. (Tranek 2021, 4.4.2)

### 5.4	Gameplay Effects
Olen aiemmissa osioissa puhunut efekteistä, joilla vaikutetaan attribuutteihin ja pelihahmon ominaisuuksiin. Viittasin niillä GAS:n konseptiin: ”Gameplay Effects (GE tai efekti)”. Efekti on "UGameplayEffect" niminen C++-luokka. Ohjelmoija tekee siitä usein aliluokan ja useita lapsiluokkia eri käyttötarkoituksia varten.

Efektejä käytetään attribuuttien ja GameplayTagien muuttamiseen, sekä ”GameplayCue” lisäämiseen ja käynnistämiseen. Esimerkkinä voisi olla tilanne, jossa vihollinen vahingoittaa pelaajaa. Vihollinen osuu pelaajaan ja efekti aiheuttaa vahinkoa pelaajan elämäpisteisiin, eli vähentää tietyn määrän pelaajan attribuutista ”CurrentHealth (Nykyiset elämäpisteet)”. Efektit muuttavat attribuutteja ”Modifiers (muunnin)” ja ”Executions (toteutuksien)” kautta. (Tranek 2021, 4.5.1.)

Efekteillä on kolme eri pituusmäärettä: ”Instant (välitön)”, ”Duration (kestoaika)” ja ”Infinite (loputon)” (kuva 5).

-	Välitöntä efektiä käytetään välittömiin attribuuttien muutoksiin. Esimerk-kinä kyseisestä efektistä voisi olla hahmon vahingon ottaminen
-	Kestoaika efektiä voisi käyttää esimerkiksi kyvyissä tai juomissa, jotka nostavat hahmon voimia tai nopeutta väliaikaisesti.
-	Loputtomat efektit poistuvat vain viittaamalla hahmon ASC:hen ja pois-tamalla ne manuaalisesti. (Tranek 2021, 4.5.1.)

![Kuva2](https://user-images.githubusercontent.com/55107172/144234712-20afa191-a24b-4791-9d57-d5d7843c07ee.png)
Kuva 5. Tässä on välitön efekti, jolla määritetään pelihahmon täydet elämäpisteet (MaxHealth)-attribuutin arvoksi kymmenentuhatta. 

#### 5.4.1	Gameplay Efektin asettaminen
Efektejä pystyy asettamaan monella tapaa ja yleensä kaikkiin liittyy funktio ”ApplyGameplayEffectToSelf” tai ”ApplyGameplayEffectToTarget”. Tämä funk-tio ottaa parametrinä viittauksen ASC:hen ja lisää valitun efektin siihen (kuva 6). (Tranek, 2021, 4.5.2.)

![Kuva3](https://user-images.githubusercontent.com/55107172/144234848-65c36122-5a55-4b8d-8898-e6556d24c295.png)
Kuva 6. Kuvassa on tilanne isku, jossa ammus on osunut kohteeseen, kohteesta on otettu dataa, data kertoo meille mihin osuimme ja nyt kohteeseen pystyy lisäämään halutun efektin.

5.5	Gameplay Ability
Kohdassa ”4 Iskut ja kyvyt” käytiin läpi, millaisia kyvyt ja iskut voisi olla ja millai-sia niiden ei välttämättä kannata olla. Tässä luvussa tarkastellaan tarkemmin, miten yksinkertainen kyky luodaan, miten kyky annetaan ja miten se aktivoi-daan.

Kun ASC:lla on hallussa jokin kyky, sen peruselinkaari on tämä (kuva 7): 
1.	Pystyykö kykyä aktivoimaan? Aktivoijan pitää tietää, onko kyky valmis suoritettavaksi, ilman sen suorittamista. Esimerkkinä, kyvyn kuvake voi-daan ottaa pois käytöstä silloin kun se ei ole käytettävissä.
2.	Kutsutaan kyvyn aktivointi eventtiä ”ActivateAbility”, jonka ohjelmoija yli kirjoittaa.
2.1	Kyvyt käynnistävät AbilityTaskeja aktivoinnin aikana, jotka hoitavat suu-rimman osan kykyjen suorittamisesta. ”Tick” funktiota ei käytetä kyvyissä niin kuin useimmissa Actoreissa ja komponenteissa. 
2.2	Onko resursseja aktivoida Ability? CommitAbility tarkastaa onko aktivoi-jalla esimerkiksi riittävästi manaa. 
3.	Aktivoidaan GameplayEvent/AnimationMontage tai Gameplay Effect (tai vaikka nämä kaikki).
4.	Lopeta kyky funktiolla (EndAbility). (Epic Games, 2004–2021.)

![Kuva6](https://user-images.githubusercontent.com/55107172/144236180-6bc90c01-571d-4e05-96d1-d0e6e9627887.png)
Kuva 7. Tässä on yksinkertaisen kyvyn elinkaari, joka toistaa animaation ja asettaa efektin kyvyn aktivoijaan. Elinkaaren vaiheet ovat kommentoitu eri vä-reillä.


## 6	GAS käyttöönotto ja pakollinen C++ osuus


GAS ei automaattisesti ole käytössä pelimoottorissa. Se on ollut jo pitkään pelimoottorin koodeissa mutta siitä tehtiin erillinen liitännäinen vasta jälkeenpäin. Liitännäinen pitää laittaa päälle käyttääkseen GAS-ominaisuuksia.
UE4 yläpalkissa kohta Settings -> Plugins -> etsi kohta ”Gameplay Abilities” (kuva 7).

![Kuva7](https://user-images.githubusercontent.com/55107172/144236545-bc8432e4-e717-449d-9bac-d0a2d5e0af92.png)
Kuva 7. Aktivoitu GAS liitännäinen.

Käynnistä nyt UE4 uudestaan ja näin GAS on aktivoitu käytettäväksi projektiin. (Epic Games, 2004–2021.)

### 6.1	Pakollinen C++ osuus

Seuraavaksi on tehtävä muokkauksia C++:n sisällä. Tämä toteutus on tehty ”Tranek’s GAS (2021)” dokumentaation kohdan ”3. Setting Up a Project Using GAS” ja ”4.1.2. Setup and Initialization” tavalla.

Jokaisella Unreal Engine-projektilla on ”ProjektinNimi.Build.cd” tyyppinen tie-dosto. GAS käyttöä varten sinne on lisättävä kolme ”string(merkkijono)”-arvoa (DependencyModule) (kuva 8). (Tranek, 2021, 3.)

![Kuva8](https://user-images.githubusercontent.com/55107172/144236763-1a2b7448-9c1a-4e7b-be60-5782bade995d.png)
Kuva 8. ”Private Dependency Modules”

Seuraavaksi pelihahmolle on annettava AbilitySystemComponent (ASC)-komponentti. Komponentin kuvaus ja idea lukee kohdassa ”6.1 Ability System Component” ja tässä osioissa asennamme sen vain valmiiksi käyttöön.
Ensiksi tarvitaan PlayerCharacter ja PlayerState C++-luokat joihin ASC voi-daan asettaa. Seuraavaksi luodaan myös uusi C++-luokka ASC:lle (kuva 9). UE4 saattaa ilmoittaa tässä vaiheessa ongelmasta, eikä ASC näy luokissa. Tämä ilmenee vanhemmilla UE4 versioilla ja korjaantuu seuraavan vaiheen jälkeen.

![Kuva9](https://user-images.githubusercontent.com/55107172/144237291-4db53ae7-d034-4af6-bc50-c335b829d0dc.png)
Kuva 9. Esimerkkejä C++-luokista, jotka luon yleensä suoraan projektin alussa.

Koska demossa luodaan moninpeli ratkaisua, kohdassa ”5.1 Ability System Component” mainittu Omistaja-Actor on pelihahmon PlayerState-luokka ja Ava-tar-Actor on pelihahmon Character-luokka. Tämä tarkoittaa, että ASC tulee elämään pelihahmon PlayerState-luokassa.

Ensiksi peritään PlayerState-luokassa ”AbilitySystemInterface”-luokka ja luomme konstruktorin (kuva 10).


![1playerstate](https://user-images.githubusercontent.com/55107172/145387751-e4ca2528-0087-4e58-aeb8-9c14d1c70e30.PNG)
Kuva 10. PlayerStateBase.h


Seuraavaksi implementoidaan IAbilitySystemInterface ja luodaan osoitin luomaamme ASC-komponenttiin (kuva 11).


![implementpointertoasc](https://user-images.githubusercontent.com/55107172/145388255-ae01f366-30ad-45bf-a535-6337183d0232.PNG)
Kuva 11. PlayerStateBase.h

!!!!!!!!!!!!! Funktio, joka palauttaa luokan ASC:n on myös pakollinen (kuva 12, kuva 13).


![Kuva12](https://user-images.githubusercontent.com/55107172/144237230-80ffbff4-2db0-4314-b85e-0950921f8605.png)
Kuva 12. PlayerStateBase.h

![Kuva13](https://user-images.githubusercontent.com/55107172/144237215-2c8be9a2-ffb3-4ee3-900d-fe49f79cc371.png)
Kuva 13. PlayerStateBase.cpp !!!!!!!!


Koska ASC on komponentti, pitää se luoda konstruktorissa.
ASC luodaan normaalisti Omistaja-Actorin luokassa, joka tässä tapauksessa on PlayerState-luokka (kuva 14). (Tranek 2021, 4.1.2.)


![Kuva14](https://user-images.githubusercontent.com/55107172/144237198-472a368f-58da-4099-8638-37d681c2f76f.png)
Kuva 14. Nyt kun PlayerState-luokka syntyy, se luo ASC:n ja laittaa sen repli-koitavaksi moninpelia varten.


Seuraavaksi PlayerState-luokan konstruktorissa määritellään vielä Replikaatiotapa ja verkonpäivitystaajuus moninpelia varten.
PlayerState-luokassa päivitystaajuus on huomattavasti pienempi, joten nos-tamme sen samaan kuin Character-luokassa (kuva 15). (Tranek 2021, 4.1.2.)


![Kuva15](https://user-images.githubusercontent.com/55107172/144237179-76637502-0a34-4ead-bdcf-095e91f1d711.png)
Kuva 15. PlayerStateBase.cpp

ASC pitää alustaa Omistaja-Actorissa, eli tässä tapauksessa PlayerState-luokassa, kuin myös Avatar-Actorissa eli tässä tapauksessa pelihahmon Cha-racter-luokassa serverillä sekä asiakalla (Server and Client). Serverin alustus tehdään, kun pelihahmo saa käyttöön PlayerController-luokan (kuva 16).
Asiakkaan alustus tehdään pelihahmon ”OnRep_PlayerState”-funktiossa (tä-män voi jättää välistä yksinpeleissä) (kuva 17). (Tranek 2021, 4.1.2.)

![Kuva16](https://user-images.githubusercontent.com/55107172/144237154-e4da113a-0999-4985-8c10-0a0c8c6f9d6a.png)
Kuva 16. PlayerController-luokassa suoritettava ASC:n alustus OnPossess-funktiossa.

![Kuva17](https://user-images.githubusercontent.com/55107172/144237125-227ec8ef-bce9-4238-94ec-1dce7953bbfd.png)
Kuva 17. Character-luokassa suoritettava ASC:n alustus OnRep_PlayerState-funktiossa.


Nyt pelihahmolla on käytössä ASC ja se on valmis GAS:n työkalujen käyttöön.

### 3.2	AttributeSet:in lisäys

Haluamme aluksi hahmoille käyttöön ainakin manan ja elämäpisteet. Tämä tarkoittaa että hahmot tarvitsevat sen nimiset attribuutit ja attribuutit sijaitsevat AttributeSet-luokassa. Luodaan ensimmäisenä AttributeSet C++-luokka (Kuva18). Lisäksi kannattaa luoda attribuutti vahingon tuottamiselle, esimerkiksi Damage(vahinko).

![attr1](https://user-images.githubusercontent.com/55107172/144851867-a03b46d7-13fb-4711-ad9e-72ab1f67c1ad.JPG)
Kuva 18. Luodaan uusi AttributeSet C++-luokka.

1. AttributeSettiin kannattaa aluksi määritellä pari valmista macroa (Kuva19). Tämä automaattisesti luo "Getter" ja "Setter"-functiot attribuuteille.

![attribtemacro](https://user-images.githubusercontent.com/55107172/145461516-ec3d3d81-2a28-4baf-9a5b-49767926c87e.PNG)
Kuva 19.  AttributeSetBase.h Macrot

2. Seuraavaksi ylikirjoitetaan kolme funktiota (Kuva 20):

- PreAttributeChange
- PostGameplayEffectExecute
- GetLifetimeReplicatedProps.

![attributeoverride](https://user-images.githubusercontent.com/55107172/145462890-57bf06b6-d6bb-4900-b0f8-adfff752c000.PNG)
Kuva 20. Ylikirjoitetaan funktiot joita AttributeSet hyödyntää.

3. Nyt luodaan ensimmäinen attribuutti: Health(elämäpisteet) sekä sille maksimi arvo jota pystyy myös muokkaamaan efekteillä, eli MaxHealth(Maksimielämäpisteet) (Kuva 21). Moninpeliä luodessa attribuuteille pitää tehdä myös OnRep-funktiot (Kuva 22). Jokainen attribuutti luodaan samalla tyylillä, ohjelmoijan pitää vain miettiä kuvaavat nimet attribuuteille, tarvitseeko ne maksimi arvoa ja pitääkö ne replikoida. Damage attribuutilla demossani ei ole maksimi arvoa ja se on olemassa vain serverillä, joten sitä ei tarvitse replikoida. Damage-attribuutti luodaan tässä tapauksessa yksinkertaisemmin (kuva 23).

![heathlandmaxhp](https://user-images.githubusercontent.com/55107172/145462935-b4757a3f-41f2-4847-b732-59546f63f61d.PNG)
Kuva 21. Health ja MaxHealth attribuutit.

![hponreps](https://user-images.githubusercontent.com/55107172/145462953-e0c0a30a-dd47-4792-8397-97963e7a89c9.PNG)
Kuva 22. OnRep-funktiot.

![damageattribute](https://user-images.githubusercontent.com/55107172/145462972-9324945a-b8d7-455c-9cf3-7b9677fd2c1b.PNG)
Kuva 23. Damage-attribuutti.

4. AttributeSetBase.h-tiedostosta löytyy nyt tarvittavat funktiot. Seuraavaksi AttributeSetBase.cpp tiedostossa pitää määritellä, mitä funktiot tekevät. Tällä hetkellä täytyy vain lisätä luodut attribuutit GetLifetimeReplicatedProps funktion sisään (Kuva 24) sekä täyttää OnRep-funtiot hyödyntäen luotua macroa (Kuva 25). Nämä kummatkin funktiot liittyvät moninpeliominaisuuksiin, joten käytän jokaisessa attribuutissa samoja määreitä. Tavoitellun demon kannalta ei ole tarvetta käyttää muita määreitä.

![16](https://user-images.githubusercontent.com/55107172/145827361-65c9d7a6-940c-495d-a351-d00f392f28a8.PNG)
Kuva 24. AttributeSetBase.cpp // Jokainen replikoitava attribuutti täytyy lisätä tähän funktioon.

![17](https://user-images.githubusercontent.com/55107172/145827374-f33294d7-4e5f-4027-9e93-91e3b9f01be7.PNG)
Kuva 25. AttributeSetBase.cpp // Jokainen replikoitava attribuutti tarvitsee samanlaisen funktion.

### 3.3 AttributeSet:in antaminen

AttributeSet on luotu ja se sisältää attribuutteja. Attribuutteja ei tietenkään voi vielä käyttää koska ei ole yhtään hahmoa, jolla AttributeSet olisi käytössä. Attribuutit lisätään InstantGameplayEffect-efektillä, Epic Gamesin suosittelemalla toteutuksella (Kuva 26).

![20](https://user-images.githubusercontent.com/55107172/145834686-c434ee9d-4262-4035-b109-24f27df104ec.PNG)
kuva 26.

Luodaan PlayerStateBase-luokkaan osoitin ja Getter-funktio samalla tavalla kuin ASC:lle (Kuva 27).

![21](https://user-images.githubusercontent.com/55107172/145834699-dc40b5b1-2761-4457-a9e8-0b0aaa48e0fa.PNG)
Kuva 27.

Useasti muuttuville attribuuteille kannattaa luoda myös Getter-funktiot PlayerState-luokkaan esimerkiksi, "float GetHealth() const;" (Kuva 28).

![22](https://user-images.githubusercontent.com/55107172/145835476-5372ecf5-d91a-4b92-a1a6-bc612565d4e6.PNG)
Kuva 28.

AttributeSet:istä kannattaa tehdä myös SubObject PlayerState-luokan konstruktorissa(Kuva 29).

![23](https://user-images.githubusercontent.com/55107172/145836165-a32e3e82-e1d1-4a69-90a7-001944c31761.PNG)
Kuva 29. PlayerState.cpp // Konstruktorissa luotu AttributeSet-SubObject.

InitializeAttributes-funktio luodaan CharacterBase-luokkaan. Maailman kaikki liikkuvat olennot periytyvät Character-Base-luokasta ja nekin tarvitsevat attribuutteja, mahdollisesti kokonaan uuden AttributeSet luokan. CharacterBase-luokkaan tulee myös TweakObjectPtr-osoitin AttributeSetBase-luokkaan, SubClass-UGameplayEffect-luokasta ja Setter-funktiot elämäpisteille ja manalle. Setter-funktioita käytetään vain hahmon syntyessä (Kuva 30). CharacterBase-luokkaan luodaan myös Getter-funktiot(Kuva 31), joita aliluokat hyödyntävä esimerkiksi, "float GetHealth() const;".

![image](https://user-images.githubusercontent.com/55107172/145840690-1ddc63d3-76e5-4fc6-841c-67f6b4722bc3.png)
Kuva 30. CharacterBase.h // Tarvittavat lisäykset CharacterBase-luokkaan.


![26](https://user-images.githubusercontent.com/55107172/145849618-208a8afd-aedc-475b-84e7-449aa5dbd118.PNG)
Kuva 31. CharacterBase.cpp // Getterit.

InitializeAttributes-funktiossa tarkistetaan onko Character-luokalla käytössä toimiva ASC-komponentti ja DefaultAttributes-luokka. Jos DefaultAttributes-luokka on käytässä, attribuutit voidaan asettaa (Kuva 33).

![24](https://user-images.githubusercontent.com/55107172/145841608-904877b7-cb1d-48e7-8489-5322de2db754.PNG)
Kuva 33. Attribuuttien asettaminen.

HeroCharacter-luokassa sijaitsevassa PosessedBy-funktion toteutuksessa, määritellään AttributeSet, kutsutaan InitializeAttributes-funktiota sekä laitetaan HeroCharacter-luokan elämäpisteet blueprintissä määriteltävään maksimielämäpiste määrään (Kuva 34). 

![27](https://user-images.githubusercontent.com/55107172/145852433-6e5cb2ac-45a4-4431-baa8-45a4b5a7dc28.PNG)
Kuva 34. HeroCharacter.cpp // Lisätään PosessedBy-funktioon tarvittavat muutokset.

AttributeSetin c++-ohjelmointi osuus on nyt valmis ja tässä vaiheessa voi luoda pelihahmon C++-luokasta ja GameMode-luokasta blueprintit ja pelihahmo projektiin käytettäväksi. Kun HeroCharacter-luokasta on tehty blueprint, sille pitää antaa efekti joka ottaa AttributeSetin käyttöön ja antaa attribuuttien maksimi arvot (Kuva 35). Itse nimeän kaikki efektit tähän tyyliin: GE_EfektinNimi.

![18](https://user-images.githubusercontent.com/55107172/146144991-17b2445b-9bdc-487b-9084-ff47b41ee037.PNG)
Kuva 35. GE_HeroAttributes.

Efektin sisällä lisätään kaksi muunninta, jotka ovat välittömiä. Nämä muuntimet ylikirjoittaa elämäpisteiden ja manan maksimi arvot (Kuva 36). HeroCharacter C++-luokassa OnPosessed-funktio laittaa attribuutit maksimiarvoon.

![28](https://user-images.githubusercontent.com/55107172/146146339-4e32d6ec-2840-4155-86c9-822a28b8cacf.PNG)
Kuva 36. GE_HeroAttributes // Instant-modifiers.

Viimeiseksi HeroCharacter-blueprintissä valitaan käyttöön juuri luomamme efekti (Kuva 37).

![29](https://user-images.githubusercontent.com/55107172/146146941-bf22882e-c5e6-44d2-ac87-08e19ad0253f.PNG)
Kuva 37. BP_HeroCharacter.

Nyt pelin käynnistäessä voi kirjoittaa konsoliin "showdebug abilitysystem", jolloin näkee pelihahmon attribuutit ja niiden arvot. Minun tapauksessani elämäpisteet, mana ja niiden maksimi määrät ovat sata. Damage-attribuutti on 0, koska sille ei ole määritelty mitään arvoa (Kuva 38).

![30](https://user-images.githubusercontent.com/55107172/146147822-3c03155e-6978-46e6-80b2-b9b5c3ea0cb9.PNG)
Kuva 38. Pelinsisäinen GAS-debugger.

### 3.3 Attribuuttien muuttaminen pelin sisällä

Tällä hetkellä projektissa on käytössä attribuutteja, mutta mikään ei muuta niitä. Tavoitteena on luoda alusta, jossa seistäessä pelihahmo ottaa vahinkoa joka sekuntti. Actor-tyyppinen Blueprint on sopivat tälläiselle alustalle. Actor tarvitsee myös BoxCollision-alueen, joka tarkistaa mitä alustaan osuu sekä Plane-muodon visualisoimaan aluetta.

Luodaan myös uusi GameplayEffect-Blueprint, GE_DamageTileDamage. Tässä efektissä määritellään mitä muokkauksia attribuutteihin tulee.

1. Vahingon pitää tapahtua joka sekuntti ja serverillä (Kuva 39).

![40](https://user-images.githubusercontent.com/55107172/146164170-5a54dae2-8d6e-4fed-9faf-a345b3b62ec6.PNG)
Kuva 39.

2. Tarkistetaan osuuko alueeseen HeroCharacter (Kuva 40).

![41](https://user-images.githubusercontent.com/55107172/146164236-759c2788-052f-4550-a322-187d423d28c7.PNG)
Kuva 40.

3. Tarkistetaan että ASC on käytössä ja tehdään siitä muuttuja selkeyden vuoksi (Kuva 41).

![42](https://user-images.githubusercontent.com/55107172/146164337-758c578f-fb07-4392-835e-0dfc42c5c484.PNG)
Kuva 41.

4. Luodaan ja annetaan ASC:lle DamageTile.Damage-tunniste (Kuva 42).

![tiledamagetag](https://user-images.githubusercontent.com/55107172/146164812-81352f4c-5cff-4f70-93eb-cde13425bc62.PNG)
Kuva 42.

5. Otetaan muistiin tietoa ASC:sta sekä valitaan haluttu efekti-luokka (Kuva 43).

![43](https://user-images.githubusercontent.com/55107172/146164944-a77d2d6e-2c5b-40ee-96ea-85518456f9e9.PNG)
Kuva 43.

6. Asetetaan efektin määrittely ASC:en, kutsutaan CharacterBase-luokan GetHealth-funktiota ja tulostetaan sen arvo näytölle (Kuva 44).

![44](https://user-images.githubusercontent.com/55107172/146164978-86af925f-cd25-46cb-a2bb-d8dbaf2d9992.PNG)
Kuva 44.

7. GE_DamageTileDamage-Blueprintissä lisätään Health-attribuuttiin -10. Vähennystä valikosta ei löydy, siksi efekteissä lisätään miinusmerkkinen luku (Kuva 45).

![damage](https://user-images.githubusercontent.com/55107172/146166102-ef1f9f6e-22bc-4ba5-8896-8bc466ca9924.PNG)
Kuva 45.

Nyt pelihahmon attribuutti vähenee joka sekuntti, jos se on alueella (Kuva 46). Pelihahmolle ei tällä hetkellä ole määritelty minimiarvoa tai kuolemista, joten elämpisteet menevät negatiivisen puolelle loputtomasti.

![hp](https://user-images.githubusercontent.com/55107172/146166370-e9fa02aa-9c22-4bfe-bf40-da8afb76e2f2.PNG)
Kuva 46.


//////////////////////////////// kykyjen luominen ja antaminen

### 4.1 Pelihahmon kykyjen aktivoiminen

Kyvyistä ja iskuista ei ole paljoa iloa, jos niitä ei pysty aktivoimaan. Luodaan actorille Plane-alusta ja BoxCollision-alue.

1. Luodaan GamePlayAbilityBase niminen C++-luokka, joka periytyy GameplayAbility-luokasta. Tähän luokkaan lisätään tarvittavia enumeraatioita, ominaisuuksia ja tunnisteita. C++-luokasta tehdään Blueprint, josta kaikki pelin kyvyt periytyvät.

2. Kaikilla Unreal Engine projekteilla on Header-tiedosto nimeltä ProjektinNimi.h. Header-tiedostoon luodaan enumeraatio-luokka. Kaikki kyvyt tullaan lisäämään Input-asetuksiin Unreal Enginessä ja siellä niille valitaan sopiva näppäin. Header-tiedostoon lisättyjen enumeraatioiden nimet täytyy olla samat kuin Unreal Enginen Input-asetuksissa (Kuva 47, 48). 

![45](https://user-images.githubusercontent.com/55107172/146435077-d70fb21b-2c2b-4c38-9a17-9e5bb2a4b0d1.PNG)
Kuva 47. ProjektinNimi.h // Enumeraatio-luokka

![46](https://user-images.githubusercontent.com/55107172/146435086-cc3063b0-458b-4089-88a8-948042dfbd0b.PNG)
Kuva 48. Unreal enginessä lisätyt Input-asetukset.

Confirm ja Cancel-enumeraatiot ovat kykyjä varten, missä esimerkiksi täytyy valita iskun tippumispaikka tai peruuttaa sen valitsemisen. None-enumeraatio on kyvyille joita pelaajan ei tarvitse käynnistää näppäimellä.

3. Jokaiselle abilitylle tulee olemaan oma näppäimensä joten se pitää saada helposti määriteltyä, tämä tapahtuu GameplayAbilityBase-luokassa. AbilityBase-luokka tarvitsee konstruktorin sekä kaksi enumeraatiota, joidenka arvon voi valita Unreal Enginessä. !!!! SELITÄ TÄHÄN MITÄ ENUMERAATIOT TEKEE !!!!!!!!!!!!. Luokkaan kannattaa myös lisätä boolean-attribuutti joka määrittelee, pitääkö kyvyn aktivoitua heti kun pelihahmo saa sen käyttöönsä(Kuva 49).

![47](https://user-images.githubusercontent.com/55107172/146437760-b29f78db-4ef3-434c-91a5-ffb17e11a8a3.PNG)
Kuva 49. GameplayAbilityBase.h

Konstruktorin sisällä voi määritelle tunnisteita jotka ovat jokaiselle kyvyille vakioita. Jos pelihahmo on kuollut tai taintunut, se voisi saada kuvanmukaiset tunnisteet (Kuva 50). Konstruktorissa määritellään myös kyvyn ilmentymäkäytäntö.

![49](https://user-images.githubusercontent.com/55107172/146438359-928171e3-2ca7-4621-82e5-688337459c89.PNG)
Kuva 50. GameplayAbilityBase.cpp

4. Lisätään HeroCharacter luokkaan funktio ja boolean-muuttuja

```c++
	bool bASCInputBound = false;
```
```c++
	void BindASCInput();
```
SetupPlayerInputComponentissa kutsutaan tätä funkkaria

### 4.2 Kykyjen antaminen hahmolle

Jotta pelihahmo pystyy käyttämään kykyjä, pitää kyvyt ensiksi antaa hahmolle. Olipa kyseessä pelaajan hahmo tai tekoälyhahmo, ne eivät pysty kykyjä käynnistämään ilman että ne omistavat kyvyn. Koska tekoäly sekä pelaajan hahmot tarvitsevat kummatkin kykyjä, CharacterBase-luokassa täytyy olla funktio jolla kyky annetaan.

1. Ensiksi lisätään ASCBase-luokkaan kaksi boolean-muuttujaa. Muuttujilla tarkistetaan onko hahmo saanut jo syntyessä annettavat kyvyt sekä mahdolliset syntyessä tapahtuvat efektit.

```c++
	bool CharacterAbilitiesGiven = false;
	bool StartupEffectsApplied = false;
```

2. Luodaan CharacterBase-luokkaan taulukko joka sisältää GameplayAbilityBase-luokan kykyjä.

```c++
UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
TArray<TSubclassOf<class UGameplayAbilityBase>> CharacterAbilities;
```
3. Tässä vaiheessa voidaan myös määrittää kyvyille taso. Tällä hetkellä määritän sen arvoksi aina yksi.

```c++
UFUNCTION(BlueprintCallable, Category = "Abilities")
virtual int32 GetAbilityLevel(EAbilityInputID AbilityID) const;
```

```c++
int32 ACharacterBase::GetAbilityLevel(EAbilityInputID AbilityID) const
{
	return 1;
}
```

4. Luodaan funktio joka käy läpi luodun CharacterAbilities-taulukon ja antaa kyvyn hahmon ASC:lle.

```c++
UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
TArray<TSubclassOf<class UGameplayAbilityBase>> CharacterAbilities;
```
```c++
	virtual void AddCharacterAbilities();
```

```c++
// Grant abilities on server
void ACharacterBase::AddCharacterAbilities()
{

	if (GetLocalRole() != ROLE_Authority || !AbilitySystemComponent.IsValid() || AbilitySystemComponent->CharacterAbilitiesGiven)
	{
		return;
	}

	for (TSubclassOf<UGameplayAbilityBase>& StartupAbility : CharacterAbilities)
	{
		AbilitySystemComponent->GiveAbility(
		FGameplayAbilitySpec(StartupAbility, GetAbilityLevel(StartupAbility.GetDefaultObject()->AbilityID), static_cast<int32>(StartupAbility.GetDefaultObject()-			>AbilityInputID), this));
	}

	AbilitySystemComponent->CharacterAbilitiesGiven = true;
}

```
5. Nyt HeroCharacter-Blueprintissä pystyy määrittelemään, mitkä kyvyt hahmolle annetaan syntyessä (Kuva 51). Tällä hetkellä ei kuitenkaan vielä ole luotu kykyä, minkä hahmo pystyisi aktivoimaan.

![50](https://user-images.githubusercontent.com/55107172/146950827-27043110-9c36-4648-997c-e4294dc79711.PNG)
Kuva 51. BP_HeroCharacter // Kykyjen lisääminen hahmolle Blueprintissä


### Oikeasti ensimmäinen kyky

Ensimmäinen kyky on nimeltään HealthRegen. Kyky lisää käyttäjälleen valitunmäärän elämäpisteitä, tekee animaation ja luo halutun partikkeli-efektin visualisoimaan kykyä.
Kyky koostuu viidestä luokasta, GameplayAblityBase-luokka, kolme GameplayEffect-luokkaa sekä GameplayCue-luokka. Luokat kannattaa selkeyden vuoksi nimetä kuvaavaksi. Itse nimeän GameplayAbility-luokat näin: GA_KyvynNimi. GameplayEffect-luokat ja GameplayCue-luokat nimetään samaa periaatetta käyttäen: GE_EfektinNimi, GE_EfektinNimiCost, CUE_HealthRegen.

1. Aluksi luodaan kyky-luokka (GA_HealthRegen) ja kyvylle efekti-luokka (GE_HealthRegen).

2. Kyvyissä on aina kaksi valmista Event-funktiota käytettävänä. ActivateAbility-funktioon määritellään mitä tapahtuu kun kyky aktivoidaan ja OnEndAbility-funktiossa voi määritellä mitä tapahtuu kun kyky lähtee pois käytöstä tai loppuu. Kyvyn alussa voi kutsua äsken luotua GetPlayerCharacter-funktiota ja tarkistaa CommitAbility-funktiolla voiko kykyä käynnistää, jos ei niin kyky on lopetettava (Kuva 54). Tässä kyvyssä voi kuitenkin GetPlayerCharacter-funktion jättää kutsumatta.

![U54](https://user-images.githubusercontent.com/55107172/148220537-a237a638-c219-413c-bf4b-62f176a56193.PNG)
Kuva 54. GA_HealthRegen

3. Seuraavaksi määritellään minkä animaation kyvyn käyttäjä toteuttaa. PlayMontageAndWait-funktiolla toteutetaan animaation käynnistys ja siinnä myös määrittellään mitä sen jälkeen tapahtuu. Kykyjen käyttämisessä on tärkeä tietää milloin kyky lopetetaan ja millon sitä ei saa vielä lopettaa. Kyky ei saa jäädä missään tapauksessa elämään, vaan sen on aina sammuttava jos sitä haluaa käyttää uusiksi. Suurimmissa osissa tämä tarkoittaa että kaikki PlayMontageAndWait-funktion OnTapahtuma-funktiot päätetään EndAbility-funktioon (Kuva 55).

![U55](https://user-images.githubusercontent.com/55107172/148221054-f69e35c6-5ce0-4cff-945e-9c0da0affbf2.PNG)
Kuva 55. GA_HeathRegen

4. Kyvyn omistajalle lisätään efekti, joka lisää omistajan elämäpisteitä ja sitten kyky lopetetaan. Jos haluaa nähdä elämäpistemäärän muuttuvan, voi tehdä kuvan mukaisen PrintString-funktion (Kuva 56). ApplyGameplayEffectToOwner-funktioon määritellään GameplayEffect-luokka, joka on luotu GE_HealthRegen luokka.
 
![U56](https://user-images.githubusercontent.com/55107172/148222130-a3cb6890-f3d8-4c53-aeee-ceb8f55bbaf8.PNG)
Kuva 56. GA_HealthRegen

5. ClassDefaults-valikossa valitaan myös kyvylle sopiva kyky-ID ja Input-ID, sekä lisätään kykyä kuvaava AbilityTag-tunniste (Kuva 57).

![U57](https://user-images.githubusercontent.com/55107172/148222384-950e5dbc-18ca-40a3-9d9b-d13bf3081a3f.PNG)
Kuva 57. GA_HealthRegen

6. GE_HealthRegen-luokassa määritetään mitä attribuuttia halutaan muokata ja miten. Tässä kyvyssä lisätään Health-attribuuttiin kaksikymmentä (Kuva 58).

![U58](https://user-images.githubusercontent.com/55107172/148222939-7956dd8b-569d-496c-a22f-3d687c91b810.PNG)
Kuva 58. GE_HealthRegen

7. GameplayEffectAssetTag kohtaan "Added" voi lisätä efektiä kuvaavan tunnisteen (Kuva 59).

![ylim1](https://user-images.githubusercontent.com/55107172/148233040-ffa3245a-5f97-46a5-b0f4-7af0e669f32c.PNG)
Kuva 59.

8. Luodaan kaksi uutta GameplayEffect-luokkaa, GE_HealthRegenCost ja GE_HealthRegenCD(Cooldown). Cost-luokassa määritetään paljonko pelaajan manaa kyky maksaa ja CD-luokassa määritellään miten usein kyvyn voi käynnistää tietyssä ajassa.

9. GE_HealthRegenCost-luokassa lisätään Mana-attribuuttiin -20 (Kuva 60) ja annetaan sille oma GameplayEffectAssetTag (Kuva 61).

![U59](https://user-images.githubusercontent.com/55107172/148224415-de6f6f80-fac5-466a-a207-084f99279a19.PNG)
Kuva 60. GE_HealthRegenCost

![U60](https://user-images.githubusercontent.com/55107172/148224438-9cdb0f74-ccf5-426a-a5a0-e0131b61ae5e.PNG)
Kuva 61. GE_HealthRegenCost

10. GE_HealthRegenCD-luokassa lisätään Duration-efekti jonka arvoksi voi määritellä haluamansa ajan sekunteina. Kykyä ei pysty käyttämään uudestaan ennen kuin tämä aika on kulunut (Kuva 62). HealthRegenCD-luokalle annetaan myös oma tunnisteensa ja tunniste myös laitetaan GrantedTag-tunnisteisiin lisättäväksi. GrantedTag-tunnisteet annetaan Actor-luokalle, jolle efekti annetaan. Eli pelihahmo saa tässä tapauksessa Skill.HealthRegen.CD-tunnisteen kahdeksaksi sekunniksi (Kuva 63).

![U61](https://user-images.githubusercontent.com/55107172/148225109-13e6eee8-d78e-40a7-b675-88117bfa0df6.PNG)
Kuva 62. GE_HealthRegenCD

![U62](https://user-images.githubusercontent.com/55107172/148225077-3caa20b9-77a0-45e0-8576-460a83d78de0.PNG)
Kuva 63. GE_healthRegenCD

11. Tämä on toimintatapa, joka koskee lähes kaikkia kykyjä, jotka tarvitsevat maksun että ne voivat käynnistyä ja "Cooldown"-toiminnon. Viimeiseksi täytyy vielä ottaa Cost-efekti ja CD-efekti käyttöön kyky-luokassa. GA_HealthRegen-luokassa on valmiiksi luodut kohdat "Cost" ja "Cooldown", jonne määritellään luodut efekti-luokat (Kuva 64).

![U63](https://user-images.githubusercontent.com/55107172/148226488-dc4d25b4-d0f8-438d-b91b-2d904d5a73d0.PNG)
Kuva 64. GA_HealthRegen

Nyt kyky maksaa valitun määrän Mana-attribuuttia ja sitä ei voi käyttää peräkkäin. Jos kyky ei toimi halutusti, kannattaa lukea dokumentaatiosta kohta "Debug".

12. Kykyyn voi halutessaan luoda vielä visuaalisen-efektin. Visuaaliset asiat hoidetaan yleensä GameplayCue-luokilla. CUE-luokka replikoituu automaattisesti kaikille pelaajille eikä niiden replikointi ole niin raskasta serverille. Optimaalisessa moninpelissä kaikki kykyjen toiminnot pitäisi tapahtua vain serverillä, ja mitä pelaajille näkyy on vain visuaalinen esitys siitä. Visuaalinen esitys yleensä on CUE-luokassa tehty partikkeli ja ääni. GameplayCueNotify_Static on luokka jota HealthRegen-kyky käyttää.

13. CUE-luokassa on valmiita funktiota jotka voi ylikirjoittaa. HealthRegen-kyvyssä tarvitaan niistä vain OnExecute-funktiota. Kun CUE-luokka käynnistyy se luo partikkelin. Partikkeli jää elämään loputtomiin jos sitä ei ole määritetty loppumaan. Demossa partikkeli on määritetty syntymään vain kerran ParticleSystem-luokassa (Kuva 65).

![U65](https://user-images.githubusercontent.com/55107172/148232267-a9e07a66-1eab-4902-bb98-58533b9ea414.PNG)
Kuva 65. CUE_HealthRegen

14. ClassDefaults-valikossa pystyy lisäämään myös GameplayCue-luokalle tunnisteen. Kun GE_HealthRegen-efekti aktivoituu se aktivoi myös GameplayCue-luokan tunnisteen perusteella (Kuva 66).

![U64](https://user-images.githubusercontent.com/55107172/148232378-882b198d-11ad-4468-9209-90c73c23aeb3.PNG)
Kuva 66. CUE_HealthRegen

15. GE_HealthRegen-luokassa ClassDefaults-valikossa on kohta "Display", johon lisätään GameplayCueTag-tunniste (Kuva 67).

![U66](https://user-images.githubusercontent.com/55107172/148232944-8d912e9c-b992-46ca-b5ee-2eff1dcf5be7.PNG)
Kuva 67. GE_HealthRegen

### Ensimmäinen kyky

![51](https://user-images.githubusercontent.com/55107172/147260728-580a1c6c-ee65-4509-be60-64d5eb494bca.PNG)

![52](https://user-images.githubusercontent.com/55107172/147260740-ec0fc574-2064-4c59-953f-2b8834435c3f.PNG)

2. Tällä hetkellä GameplayAbilityBase-luokka on riittävä käytettäväksi ja nyt täytyy luoda luokka kyvylle, joka periytyy GameplayAbilityBase-luokasta. Kyvyt nimetään yleensä tyylillä "GA_KyvynNimi" ja efektit "GE_EfektinNimi". GA tarkoittaa GameplayAbility ja GE GameplayEffect.

3. Kyvyissä on aina kaksi valmista Event-funktiota käytettävänä. ActivateAbility-funktioon määritellään mitä tapahtuu kun kyky aktivoidaan ja OnEndAbility-funktiossa voi määritellä mitä tapahtuu kun kyky lähtee pois käytöstä tai loppuu. Kyvyn alussa voi kutsua äsken luomaamme GetPlayerCharacter-funktiota ja tarkistaa CommitAbility-funktiolla voiko kykyä käynnistää, jos ei niin kyky on lopetettava (Kuva 54).

![53](https://user-images.githubusercontent.com/55107172/147578006-6401a886-7273-4e72-85a0-76947365f4c8.PNG)
Kuva 54. GA_Fireball

4. Seuraavaksi määritellään minkä animaation kyvyn käyttäjä toteuttaa. PlayMontageAndWait-funktiolla toteutetaan animaation käynnistys ja siinnä myös määrittellään mitä sen jälkeen tapahtuu. Kykyjen käyttämisessä on tärkeä tietää milloin kyky lopetetaan ja millon sitä ei saa vielä lopettaa. Kyky ei saa jäädä missään tapauksessa elämään, vaan sen on aina sammuttava jos sitä haluaa käyttää uusiksi. Suurimmissa osissa tämä tarkoittaa että kaikki PlayMontageAndWait-funktion OnTapahtuma-funktiot päätetään EndAbility-funktioon (Kuva 55).

5. Tässä kyvyssä synnytetään projektiili, joka on erillinen luokkansa. Projektiili luodaan SpawnActorFromClass-funktiolla. Funktiossa määritellään luotava luokka, miten päin se syntyy maailmaan, törmäys-asetuksia sekä omistaja ja Instigator-luokka. Projektiili luodaan kohdassa kuusi joten Class-funktion voi vielä jättää tyhjäksi. Omistaja ja Instigator-luokka on GetPlayerCharacter-funktiolla saatu HeroCharacter-luokka. HeroCharacter-luokasta voi myös ottaa GetActorTransform-funktiolla arvon projektiilin SpawnTransform-muuttujaan (Kuva 55).

![54](https://user-images.githubusercontent.com/55107172/147578028-d36d6210-e65a-4428-a4ac-ef7f9afdc99a.PNG)
Kuva 55. GA_Fireball // Toistetaan animaatio ja synnytetään projektiili.

6. Nyt on hyvä aika luoda alustava projektiili-Blueprint. Tarkoituksena projektiililla on lentää määritelty matka ja tarkastaa mihin se osuu. Osuttuaan se lähettää tapahtuman EvenTag-muodossa projektiilin Instigator-luokalle, eli tässä tapauksessa HeroCharacter-luokalle. Luodaan siis uusi Actor-Blueprint, esimerkiksi PROJ_Fireball. Myöhemmin luodaan vielä ProjectileBase-Blueprint, josta kaikki projektiilit periytyvät. Projektiilille luodaan Sphere-muoto, Box/SphereCollision-törmäysmuoto ja ProjectileMovement-komponentti (Kuva 56). 
Projektiili-luokka on nyt olemassa, joten sen pystyy laittamaan nyt kohdassa viisi määriteltyyn funktioon synnytettäväksi luokaksi GA_Fireball-luokan sisällä.

![59](https://user-images.githubusercontent.com/55107172/147578239-0f09d576-95b6-4b65-8dce-41087a87bde9.PNG)
Kuva 56. PROJ_Fireball


7. Määritellään BeginPlay-tapahtumassa miten pitkään projektiili kuuluu lentää ilmassa, ennen kuin se katoaa (Kuva 57).

![60](https://user-images.githubusercontent.com/55107172/147578260-66106176-80b6-4734-b88a-93cf839927f6.PNG)
Kuva 57. PROJ_Fireball // Projektiilin lentomatka määritetään näin.

8. Tarkistetaan mihin Collision-komponentti osuu OverLap-funktiolla. Nyt haluan että projektiili reagoi vain luomaani BP_TestEnemyCharacter-Blueprinttiin, joka on vain HeroCharacter-aliluokka erivärisenä. Jatkossa luodaan EnemyCharacterBase-luokka josta kaikki viholliset periytyvät ja osumaa voi tarkastella niihin. Kannattaa myös huomioida että ensimmäisenä Collision-komponentti luultavasti osuu projektiilin luojaan ja pitääkö sen tuhoutua jos se osuu vaikka seinään. Tällä hetkellä riittää kuitenkin että se reagoi vain yhteen haluttuun kohteeseen (Kuva 58).

![61](https://user-images.githubusercontent.com/55107172/147580266-b6e1e234-c8c9-42e3-89c1-6ebe4bd058f5.PNG)
Kuva 58.  PROJ_Fireball

9. Jos projektiili osuu oikeaan kohteeseen siitä kannattaa ottaa ylös tietoa jota voi hyödyntää. Tähän tarvitaan osutun kohteen ASC jonka saa helposti GetAbilitySystemComponent-funktiolla. Kun ASC on muistissa, siitä voi luoda GameplayEventData-rakenteen. Rakenteeseen kannattaa tässä tapauksessa lisätä Target-viittaus joka on osuttu Actor-luokka ja valinnaiseksi objektiksi voi laittaa sen ASC:n.
Nyt kyvyn Instigator-luokalle on ilmoitettava että kyky on osunut kohteeseen. Tämä tehdään SendGameplayEventToActor-funktiolla johon luodaan uusi Event-tunniste. Tunniste kannattaa olla tapahtumaa kuvaava ja sen tyyli on sama kuin kaikissa GAS:n tunnisteissa, esimerkiksi Projectile.DamageActivation. Funktioon liitetään myös Payload-rakenteeseen äsken luotu GameplayEventData-rakenne sekä Actor-määrittelyyn GetInstigator-funktiolla projektiilin Instigator-luokka. Viimeisenä tuhotaan projektiili DestroyActor-funktiolla (Kuva 59).

![62](https://user-images.githubusercontent.com/55107172/147582889-6eb92f39-f812-438b-bc8c-9ca8b7a85a86.PNG)
Kuva 59. PROJ_Fireball

10. Viimeseinä kyvyn sisällä pitää ottaa vastaan kohdassa yhdeksän luotu Projectile.DamageActivation-tapahtumatunniste. Kun projektiili on synnytetty kyvyn sisällä, pitää kyvyn odottaa tapahtumaa ja määrittää mitä sitten tapahtuu. Tämä onnistuu WaitGameplayEvent-funktiolla. Funktiossa valitaan mitä tapahtumaa odotetaan ja se määritetään tunnisteella. Tunniste on projektiili-luokassa lähetetty Projectile.DamageAction-tunniste. Seuraavaksi määritellään mitä tapahtuu kun tunniste on saatu ja tällä hetkellä riittää että tiedämme että kyky on saanut Event-tunnisteen onnistuneesti. Viimeiseki lopetetaan ability EndAbility-funktiolla (Kuva 60).

![57](https://user-images.githubusercontent.com/55107172/147583522-0548a539-a22f-445f-85b1-42d4c4785613.PNG)
Kuva 60. GA_Fireball



![63](https://user-images.githubusercontent.com/55107172/147585316-c4b1e933-0edc-4a0b-8f3a-cbcb58739f55.PNG)
Kuva 61. Luodun GameplayAbility-luokan idea.

![64](https://user-images.githubusercontent.com/55107172/147585322-7f0965e9-5d24-401b-a80b-99b4ae68b5fb.PNG)
Kuva 62. Luodun Projectile-luokan idea.

## 7.1 Käyttöliittymä

Tässä osiossa toteutan yksinkertaisen käyttöliittymän. Käyttöliittymän idea on vain näyttää visuaalisesti, milloin kykyjä pystyy käyttämään ja milloin ei. Käyttöliittymästä näkee myös Mana-attribuutin sekä Health-attribuutin. Käyttöliittymä ei ole projektin idea, joten käyn sen läpi nopeasti ja koodi on täysin sama kuin Tranekin GAS-dokumentaatiossa.

1. Ensiksi luodaan C++-luokka UserWidget. Luokkaan lisätään käyttöliittymässä käytettävien attribuuttejen Setter-funktiot max,- current ja prosentti-attribuuteille.

```c++

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetMaxHealth(float MaxHealth);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentHealth(float CurrentHealth);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetHealthPercentage(float HealthPercentage);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetHealthRegenRate(float HealthRegenRate);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetMaxMana(float MaxMana);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentMana(float CurrentMana);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetManaPercentage(float ManaPercentage);

```
2. Käyttöliittymä tarkastelee attribuuttien arvoja ASyncTask-funktiolla. Luodaan BlueprintAsyncActionBase C++-luokka, sen funktiot ja paramentrit.

```c++
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAttributeChanged, FGameplayAttribute, Attribute, float, NewValue, float, OldValue);
```

```c++
public:

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnAttributeChanged;

	// Listens for an attribute changing.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncTaskAttributeChanged* ListenForAttributeChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAttribute Attribute);

	// Listens for an attribute changing.
	// Version that takes in an array of Attributes. Check the Attribute output for which Attribute changed.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncTaskAttributeChanged* ListenForAttributesChange(UAbilitySystemComponent* AbilitySystemComponent, TArray<FGameplayAttribute> Attributes);

	// You must call this function manually when you want the AsyncTask to end.
	// For UMG Widgets, you would call it in the Widget's Destruct event.
	UFUNCTION(BlueprintCallable)
	void EndTask();

protected:

	UPROPERTY()
	UAbilitySystemComponent* ASC;
	
	FGameplayAttribute AttributeToListenFor;
	TArray<FGameplayAttribute> AttributesToListenFor;

	void AttributeChanged(const FOnAttributeChangeData& Data);

```
```c++
UAsyncTaskAttributeChanged* UAsyncTaskAttributeChanged::ListenForAttributeChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAttribute Attribute)
{
	UAsyncTaskAttributeChanged* WaitForAttributeChangedTask = NewObject<UAsyncTaskAttributeChanged>();
	WaitForAttributeChangedTask->ASC = AbilitySystemComponent;
	WaitForAttributeChangedTask->AttributeToListenFor = Attribute;

	if (!IsValid(AbilitySystemComponent) || !Attribute.IsValid())
	{
		WaitForAttributeChangedTask->RemoveFromRoot();
		return nullptr;
	}

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(WaitForAttributeChangedTask, &UAsyncTaskAttributeChanged::AttributeChanged);

	return WaitForAttributeChangedTask;
}

UAsyncTaskAttributeChanged* UAsyncTaskAttributeChanged::ListenForAttributesChange(UAbilitySystemComponent* AbilitySystemComponent, TArray<FGameplayAttribute> Attributes)
{
	UAsyncTaskAttributeChanged* WaitForAttributeChangedTask = NewObject<UAsyncTaskAttributeChanged>();
	WaitForAttributeChangedTask->ASC = AbilitySystemComponent;
	WaitForAttributeChangedTask->AttributesToListenFor = Attributes;

	if (!IsValid(AbilitySystemComponent) || Attributes.Num() < 1)
	{
		WaitForAttributeChangedTask->RemoveFromRoot();
		return nullptr;
	}

	for (FGameplayAttribute Attribute : Attributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(WaitForAttributeChangedTask, &UAsyncTaskAttributeChanged::AttributeChanged);
	}

	return WaitForAttributeChangedTask;
}

void UAsyncTaskAttributeChanged::EndTask()
{
	if (IsValid(ASC))
	{
		ASC->GetGameplayAttributeValueChangeDelegate(AttributeToListenFor).RemoveAll(this);

		for (FGameplayAttribute Attribute : AttributesToListenFor)
		{
			ASC->GetGameplayAttributeValueChangeDelegate(Attribute).RemoveAll(this);
		}
	}

	SetReadyToDestroy();
	MarkPendingKill();
}

void UAsyncTaskAttributeChanged::AttributeChanged(const FOnAttributeChangeData& Data)
{
	OnAttributeChanged.Broadcast(Data.Attribute, Data.NewValue, Data.OldValue);
}
```
ListenForAttributeChange-funktiot odottaa valittujen attribuuttien muuttumista ja käyttöliittymää päivitetään muutoksien mukaan. Funktioita on kaksi, toinen yhdelle attribuutille ja toinen attribuutti-taulukolle. EndTask-funktiota kutsutaan manuaalisesti käyttöliittymässä, ettei AsyncTask-funktio jää elämään ikuisesti.

3. Cooldown-efektin visualisoimiseksi luon myös UBlueprintAsyncActionBase C++-luokan ja annan sille tarvittavat parametrit ja funktiot. 

```c++
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCooldownChanged, FGameplayTag, CooldownTag, float, TimeRemaining, float, Duration);
```


```c++
public:
	UPROPERTY(BlueprintAssignable)
	FOnCooldownChanged OnCooldownBegin;

	UPROPERTY(BlueprintAssignable)
	FOnCooldownChanged OnCooldownEnd;

	// Listens for changes (Begin and End) to cooldown GameplayEffects based on the cooldown tag.
	// UseServerCooldown determines if the Sever's cooldown is returned in addition to the local predicted cooldown.
	// If using ServerCooldown, TimeRemaining and Duration will return -1 to signal local predicted cooldown has begun.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncTaskCooldownChanged* ListenForCooldownChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayTagContainer CooldownTags, bool UseServerCooldown);

	// You must call this function manually when you want the AsyncTask to end.
	// For UMG Widgets, you would call it in the Widget's Destruct event.
	UFUNCTION(BlueprintCallable)
	void EndTask();

protected:
	UPROPERTY()
	UAbilitySystemComponent* ASC;

	FGameplayTagContainer CooldownTags;

	bool UseServerCooldown;

	virtual void OnActiveGameplayEffectAddedCallback(UAbilitySystemComponent* Target, const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle);
	virtual void CooldownTagChanged(const FGameplayTag CooldownTag, int32 NewCount);

	bool GetCooldownRemainingForTag(FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration);

```

```c++
UAsyncTaskCooldownChanged * UAsyncTaskCooldownChanged::ListenForCooldownChange(UAbilitySystemComponent * AbilitySystemComponent, FGameplayTagContainer InCooldownTags, bool InUseServerCooldown)
{
	UAsyncTaskCooldownChanged* ListenForCooldownChange = NewObject<UAsyncTaskCooldownChanged>();
	ListenForCooldownChange->ASC = AbilitySystemComponent;
	ListenForCooldownChange->CooldownTags = InCooldownTags;
	ListenForCooldownChange->UseServerCooldown = InUseServerCooldown;

	if (!IsValid(AbilitySystemComponent) || InCooldownTags.Num() < 1)
	{
		ListenForCooldownChange->EndTask();
		return nullptr;
	}

	AbilitySystemComponent->OnActiveGameplayEffectAddedDelegateToSelf.AddUObject(ListenForCooldownChange, &UAsyncTaskCooldownChanged::OnActiveGameplayEffectAddedCallback);

	TArray<FGameplayTag> CooldownTagArray;
	InCooldownTags.GetGameplayTagArray(CooldownTagArray);
	
	for (FGameplayTag CooldownTag : CooldownTagArray)
	{
		AbilitySystemComponent->RegisterGameplayTagEvent(CooldownTag, EGameplayTagEventType::NewOrRemoved).AddUObject(ListenForCooldownChange, &UAsyncTaskCooldownChanged::CooldownTagChanged);
	}

	return ListenForCooldownChange;
}

void UAsyncTaskCooldownChanged::EndTask()
{
	if (IsValid(ASC))
	{
		ASC->OnActiveGameplayEffectAddedDelegateToSelf.RemoveAll(this);

		TArray<FGameplayTag> CooldownTagArray;
		CooldownTags.GetGameplayTagArray(CooldownTagArray);

		for (FGameplayTag CooldownTag : CooldownTagArray)
		{
			ASC->RegisterGameplayTagEvent(CooldownTag, EGameplayTagEventType::NewOrRemoved).RemoveAll(this);
		}
	}

	SetReadyToDestroy();
	MarkPendingKill();
}

void UAsyncTaskCooldownChanged::OnActiveGameplayEffectAddedCallback(UAbilitySystemComponent * Target, const FGameplayEffectSpec & SpecApplied, FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer AssetTags;
	SpecApplied.GetAllAssetTags(AssetTags);
	
	FGameplayTagContainer GrantedTags;
	SpecApplied.GetAllGrantedTags(GrantedTags);

	TArray<FGameplayTag> CooldownTagArray;
	CooldownTags.GetGameplayTagArray(CooldownTagArray);

	for (FGameplayTag CooldownTag : CooldownTagArray)
	{
		if (AssetTags.HasTagExact(CooldownTag) || GrantedTags.HasTagExact(CooldownTag))
		{
			float TimeRemaining = 0.0f;
			float Duration = 0.0f;
			// Expecting cooldown tag to always be first tag
			FGameplayTagContainer CooldownTagContainer(GrantedTags.GetByIndex(0));
			GetCooldownRemainingForTag(CooldownTagContainer, TimeRemaining, Duration);

			if (ASC->GetOwnerRole() == ROLE_Authority)
			{
				// Player is Server
				OnCooldownBegin.Broadcast(CooldownTag, TimeRemaining, Duration);
			}
			else if (!UseServerCooldown && SpecApplied.GetContext().GetAbilityInstance_NotReplicated())
			{
				// Client using predicted cooldown
				OnCooldownBegin.Broadcast(CooldownTag, TimeRemaining, Duration);
			}
			else if (UseServerCooldown && SpecApplied.GetContext().GetAbilityInstance_NotReplicated() == nullptr)
			{
				// Client using Server's cooldown. This is Server's corrective cooldown GE.
				OnCooldownBegin.Broadcast(CooldownTag, TimeRemaining, Duration);
			}
			else if (UseServerCooldown && SpecApplied.GetContext().GetAbilityInstance_NotReplicated())
			{
				// Client using Server's cooldown but this is predicted cooldown GE.
				// This can be useful to gray out abilities until Server's cooldown comes in.
				OnCooldownBegin.Broadcast(CooldownTag, -1.0f, -1.0f);
			}
		}
	}
}

void UAsyncTaskCooldownChanged::CooldownTagChanged(const FGameplayTag CooldownTag, int32 NewCount)
{
	if (NewCount == 0)
	{
		OnCooldownEnd.Broadcast(CooldownTag, -1.0f, -1.0f);
	}
}

bool UAsyncTaskCooldownChanged::GetCooldownRemainingForTag(FGameplayTagContainer InCooldownTags, float & TimeRemaining, float & CooldownDuration)
{
	if (IsValid(ASC) && InCooldownTags.Num() > 0)
	{
		TimeRemaining = 0.f;
		CooldownDuration = 0.f;

		FGameplayEffectQuery const Query = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(InCooldownTags);
		TArray< TPair<float, float> > DurationAndTimeRemaining = ASC->GetActiveEffectsTimeRemainingAndDuration(Query);
		if (DurationAndTimeRemaining.Num() > 0)
		{
			int32 BestIdx = 0;
			float LongestTime = DurationAndTimeRemaining[0].Key;
			for (int32 Idx = 1; Idx < DurationAndTimeRemaining.Num(); ++Idx)
			{
				if (DurationAndTimeRemaining[Idx].Key > LongestTime)
				{
					LongestTime = DurationAndTimeRemaining[Idx].Key;
					BestIdx = Idx;
				}
			}

			TimeRemaining = DurationAndTimeRemaining[BestIdx].Key;
			CooldownDuration = DurationAndTimeRemaining[BestIdx].Value;

			return true;
		}
	}

	return false;
}

```
Funktiot tarkastelee kykyjen Cooldown-tunnisteen tilaa ja sen perusteella voi muokata käyttöliittymän ikoneja. 

4. Luodusta UserWidget C++-luokasta tehdään Blueprint, joka sisältää Canvas-paneelin, manalle ja elämäpisteille ProgressBar-palkit ja kuva kykyjen ikonien kehikolle (Kuva 77).

![65](https://user-images.githubusercontent.com/55107172/148731024-a210e9f5-3091-4f9f-9a2f-932c96539b0c.PNG)
Kuva 77. UI_HeroCharacter // Pelatessa näkyvä käyttöliittymä.

6. Käyttöliittymä-blueprint tarvitsee Current,- ja Max,- Float-muuttujat elämäpisteille. UserWidget C++-luokassa luodut Set-funktiot kutsutaan Käyttöliittymän Blueprintissä, ja muuttujien arvot asetetaan niiden kautta (Kuva 78). Blueprintille luodaan myös kaksi funktiota, SetHealth ja SetMana (Kuva 79).

![66](https://user-images.githubusercontent.com/55107172/148733198-3ebfa7d5-3208-4be8-8b36-c4d07394550b.PNG)
Kuva 78. UI_HeroCharacter

![67](https://user-images.githubusercontent.com/55107172/148733320-5e36ce49-ac12-4a99-b916-5647fd6a6115.PNG)
Kuva 79. UI_HeroCharacter

7. Attribuuttien muutoksien kuuntelemiseen tarvitsee aluksi ASC:n, joka haetaan käyttöliittymän omistajalta (Kuva 80). Haluan kuunnella Health,- ja Mana-attribuuttia joten kutsun luotua ASyncListenForAttributesChange-funktiota ja luon sille taulukon joka pitää sisällään halutut attribuutit (Kuva 81). Seuraavaksi tarkistetaan kumpaa attribuuttia muutetaan ja asetetaan sen perusteella CurrentHealth-attribuutin tai CurrentMana-attribuutin arvo (Kuva 82).

![68](https://user-images.githubusercontent.com/55107172/148734387-091b8265-4b5c-4ce3-a5ea-71a6ecede03d.PNG)
Kuva 80. UI_HeroCharacter

![69](https://user-images.githubusercontent.com/55107172/148734397-302d841f-1f0e-488d-8035-9b46c67bb0c7.PNG)
Kuva 81. UI_HeroCharacter

![70](https://user-images.githubusercontent.com/55107172/148734407-fded8a3c-a143-4171-accd-28e8971f006b.PNG)
Kuva 82. UI_HeroCharacter

8. Viimeisenä luodaan pelihahmon Controller-luokasta Blueprint ja laitetaan käyttöliittymä näkymään pelaajalle (Kuva 83).

![71](https://user-images.githubusercontent.com/55107172/148734699-4a7bc663-5ebd-41e0-b1ed-41f5f5ab41e7.PNG)
Kuva 83. BP_HeroPlayerController

![image](https://user-images.githubusercontent.com/55107172/148734619-ec74835c-0ed4-492c-9766-2dbe3f4f01b9.png)


### 7.1.1 Kykyjen visualisointi käyttöliittymässä

Kyvyt täytyy olla merkitty käyttöliittymään selkeyden ja pelaajan auttamisen vuoksi. Kyvyt kovakoodataan projektissa niiden omille paikoilleen ja niiden visualisoimiseen käytetään nopeasti itsetehtyjä ikoneja. Kunnollisen käyttöliittymän suunnittelu vaatii työtä ja aikaa, joten tässä vaiheessa kykyjen ikonien ja Cooldown-efektin näyttäminen ikoneissa riittää. Toteutus luodaan mahdollisimman yksinkertaisesti.

1. Aluksi tarvitaan kehikko mihin kykyjen ikonit sijoitetaan. Ikonien päälle voi halutessa myös lisätä teksti-laatikolla kirjaimen, joka kuvastaa mistä näppäimestä kyky aktivoidaan (kuva 84).

![hud1](https://user-images.githubusercontent.com/55107172/149519420-5221f221-2a5a-4353-8ab2-522094c420a6.PNG)
Kuva 84. UI_HeroCharacter

2. ListenForAttributesChange-funktiosta jatketaan liittämällä Exec-pinni ListenForCooldownChange-funktioon. Funktioon liitetään PlayerState-luokasta saatu ASC ja luodaan taulukko käsitellyistä tunnisteista. Tällä hetkellä minulla on kaksi kykyä ja niillä kummallakin on Cooldown-efektille tunnisteet. UseServerCooldown-boolean muuttuja laitetaan myös todeksi (kuva 85).

![hud2](https://user-images.githubusercontent.com/55107172/149519464-c02490ad-6ade-4818-be5c-0658b59a679f.PNG)
Kuva 85. UI_HeroCharacter

3. ListenForCooldownChange-funktiossa on määritelty kaksi funktiota, OnCooldownBegin ja OnCooldownEnd. Molemmissa tarkistetaan aluksi minkä kyvyn tunniste on kyseessä. OnCooldownEnd-funktiossa laitetaan vain kuvien läpikuultamattomuus arvolle yksi. OnCooldownBegin-funktiossa voidaan tarkistaa paljon aikaa on jälellä ja asettaa kuville sen perusteella läpikuultamattomuus arvo (kuva 86).

![Hud4](https://user-images.githubusercontent.com/55107172/149519693-3d134673-eaba-4468-9a18-c95f5b76a29b.PNG)
kuva 86. UI_HeroCharacter

Nyt kun ASC:lla on Cooldown-tunniste, ikonit muuttuvat läpikuultaviksi. Kun Cooldown-tunniste lähtee, ikonit muuttuvat normaaliksi.

```c++
```

![ai1r](https://user-images.githubusercontent.com/55107172/149536025-cb6d4c95-33c7-4844-a017-928747358a4e.PNG)

![ai2](https://user-images.githubusercontent.com/55107172/149536098-eac86e3b-cd77-4fac-8fce-4fdd8f69fd9a.PNG)

![ai3](https://user-images.githubusercontent.com/55107172/149536133-24b3da28-5e50-4363-911c-9367ee4a93da.PNG)

![ai4](https://user-images.githubusercontent.com/55107172/149536290-0f310169-f48d-4524-9db2-6a80decf266b.PNG)
![ai5](https://user-images.githubusercontent.com/55107172/149536354-f2fae6de-f094-4c6b-a4e6-061236f22fe3.PNG)


## DamageText

1. Luodaan uusi WidgetComponent-C++-luokka. 
2. Luokkaan lisätään yksi junlkinen funktio jota käytetään tekstin asettamiseksi Blueprintissä.
	c++//
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetDamageText(float Damage);

4. 

![EnemyBar1](https://user-images.githubusercontent.com/55107172/150975025-f38ce231-850f-4f8a-b356-479d739acba1.PNG)

![enemybar2](https://user-images.githubusercontent.com/55107172/150976007-a24b2c6f-5f92-4617-a95d-f477ac8c3655.PNG)

![dmgnum1](https://user-images.githubusercontent.com/55107172/150982218-24b4a65e-610c-4f56-b608-76f5c4e4151c.PNG)

![dmgnum1](https://user-images.githubusercontent.com/55107172/150982917-3e66419e-f608-4cf8-ab6c-4a4254f0a9ce.PNG)
![dmgnum2](https://user-images.githubusercontent.com/55107172/150983051-cf886d30-682f-44dd-8d96-ef9bbe2e0f1d.PNG)
![dmgnum3](https://user-images.githubusercontent.com/55107172/150984573-da41955f-4061-4540-967c-fc0bd986966e.PNG)

## 7.2 Viholliset

## 7.3 Vahinkonumero ja elämäpistepalkki

## 7.4 Uudet funktiot

## 7.5 ...



## 7	Lähdeluettelo


Epic Games. 2004–2021. Gameplay Ability. https://docs.unrealengine.com/4.27/en-US/InteractiveExperiences/GameplayAbilitySystem/GameplayAbility/. 25.09.2021


Tranek. 2021. GAS Documentation. https://github.com/tranek/GASDocumentation. 01.10.2021


Prinke, M. 2021. A Guided Tour of Gameplay Abilities. Inside Unreal. YouTube. https://www.youtube.com/watch?v=YvXvWa6vbAA&t=49s. 06.10.2021


SabreDartStudios. (26.3.2018). Intro to Gameplay Abilities in Unreal Engine 4 [video]. Haettu osoitteesta https://www.youtube.com/watch?v=Ev2P6BTUxN0. 06.10.2021


Wikipedia.2021. Fortnite. https://fi.wikipedia.org/wiki/Fortnite. 18.10.2021.
