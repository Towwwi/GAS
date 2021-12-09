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

### 3.2	AttributeSet lisäys

Haluamme aluksi hahmoille käyttöön ainakin manan ja elämäpisteet. Tämä tarkoittaa että hahmot tarvitsevat sen nimiset attribuutit ja attribuutit sijaitsevat AttributeSet-luokassa. Luodaan ensimmäisenä AttributeSet C++-luokka (Kuva18). Lisäksi kannattaa luoda attribuutti vahingon tuottamiselle, esimerkiksi Damage(vahinko).

![attr1](https://user-images.githubusercontent.com/55107172/144851867-a03b46d7-13fb-4711-ad9e-72ab1f67c1ad.JPG)
Kuva 18. Luodaan uusi AttributeSet C++-luokka.

AttributeSettiin kannattaa aluksi määritellä pari valmista macroa (Kuva19). Tämä automaattisesti luo "Getter" ja "Setter"-functiot attribuuteille.

![attribtemacro](https://user-images.githubusercontent.com/55107172/145461516-ec3d3d81-2a28-4baf-9a5b-49767926c87e.PNG)
Kuva 19.  AttributeSetBase.h Macrot

Seuraavaksi ylikirjoitetaan kolme funktiota (Kuva 20):

- PreAttributeChange
- PostGameplayEffectExecute
- GetLifetimeReplicatedProps.

![attributeoverride](https://user-images.githubusercontent.com/55107172/145462890-57bf06b6-d6bb-4900-b0f8-adfff752c000.PNG)
Kuva 20. Ylikirjoitetaan funktiot joita AttributeSet hyödyntää.

Nyt luodaan ensimmäinen attribuutti: Health(elämäpisteet) sekä sille maksimi arvo jota pystyy myös muokkaamaan efekteillä, eli MaxHealth(Maksimielämäpisteet) (Kuva 21). Moninpeliä luodessa attribuuteille pitää tehdä myös OnRep-funktiot (Kuva 22). Jokainen attribuutti luodaan samalla tyylillä, ohjelmoijan pitää vain miettiä kuvaavat nimet attribuuteille, tarvitseeko ne maksimi arvoa ja pitääkö ne replikoida. Damage attribuutilla demossani ei ole maksimi arvoa ja se on olemassa vain serverillä, joten sitä ei tarvitse replikoida. Damage-attribuutti luodaan tässä tapauksessa yksinkertaisemmin (kuva 23).

![heathlandmaxhp](https://user-images.githubusercontent.com/55107172/145462935-b4757a3f-41f2-4847-b732-59546f63f61d.PNG)
Kuva 21. Health ja MaxHealth attribuutit.

![hponreps](https://user-images.githubusercontent.com/55107172/145462953-e0c0a30a-dd47-4792-8397-97963e7a89c9.PNG)
Kuva 22. OnRep-funktiot.

![damageattribute](https://user-images.githubusercontent.com/55107172/145462972-9324945a-b8d7-455c-9cf3-7b9677fd2c1b.PNG)
Kuva 23. Damage-attribuutti.

## 7	Lähdeluettelo


Epic Games. 2004–2021. Gameplay Ability. https://docs.unrealengine.com/4.27/en-US/InteractiveExperiences/GameplayAbilitySystem/GameplayAbility/. 25.09.2021


Tranek. 2021. GAS Documentation. https://github.com/tranek/GASDocumentation. 01.10.2021


Prinke, M. 2021. A Guided Tour of Gameplay Abilities. Inside Unreal. YouTube. https://www.youtube.com/watch?v=YvXvWa6vbAA&t=49s. 06.10.2021


SabreDartStudios. (26.3.2018). Intro to Gameplay Abilities in Unreal Engine 4 [video]. Haettu osoitteesta https://www.youtube.com/watch?v=Ev2P6BTUxN0. 06.10.2021


Wikipedia.2021. Fortnite. https://fi.wikipedia.org/wiki/Fortnite. 18.10.2021.
