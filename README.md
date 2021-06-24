

## 创建型模式

### 工厂方法模式

- 一种创建型设计模式，其在父类中提供一个创建对象的方法，允许子类决定实例化对象的类型。

- 工厂方法模式结构

  ![image-20210622111433819](resource\image-20210622111433819-1624331675181.png)
  1. **产品** （Product） 将会对**接口**进行声明。 对于所有由创建者及其子类构建的对象， 这些接口都是通用的。

  2. **具体产品** （Concrete Products） 是产品接口的不同实现。

  3. **创建者** （Creator） 类声明返回产品对象的工厂方法。 该方法的返回对象类型必须与产品接口相匹配。

     可以将工厂方法声明为**抽象方法，** 强制要求每个子类以不同方式实现该方法。 或者， 你也可以在基础工厂方法中返回默认产品类型。

  4. **具体创建者** （Concrete Creators） 将会重写基础工厂方法， 使其返回不同类型的产品。并不一定每次调用工厂方法都会**创建**新的实例。 工厂方法也可以返回缓存、 对象池或其他来源的已有对象。

- 适用场景

  - 当在编写代码的过程中 ，如果无法预知对象确切类别及其依赖关系时，可使用工厂方法
  - 如果你希望复用现有对象来节省系统资源，而不是每次都重新创建对象，可使用工厂方法
  -  如果你希望用户能扩展你软件库或框架的内部组件，可使用工厂方法。

- 实现方式
  1. 让所有产品都遵循同一接口。 该接口必须声明对所有产品都有意义的方法。
  2. 在创建类中添加一个空的工厂方法。 该方法的返回类型必须遵循通用的产品接口。
  3. 在创建者代码中找到对于产品构造函数的所有引用。 将它们依次替换为对于工厂方法的调用， 同时将创建产品的代码移入工厂方法。 你可能需要在工厂方法中添加临时参数来控制返回的产品类型。
  4. 为工厂方法中的每种产品编写一个创建者子类， 然后在子类中重写工厂方法， 并将基本方法中的相关创建代码移动到工厂方法中。
  5. 如果应用中的产品类型太多， 那么为每个产品创建子类并无太大必要， 这时你也可以在子类中复用基类中的控制参数。
  6. 如果代码经过上述移动后， 基础工厂方法中已经没有任何代码， 你可以将其转变为抽象类。 如果基础工厂方法中还有其他语句， 你可以将其设置为该方法的默认行为。
- 工厂方法模式优缺点
  - 优点
    - 可以避免创建者和具体产品之间的紧密耦合。
    -  *单一职责原则*。 你可以将产品创建代码放在程序的单一位置， 从而使得代码更容易维护。
    - *开闭原则*。 无需更改现有客户端代码， 你就可以在程序中引入新的产品类型。
  - 缺点
    - 应用工厂方法模式需要引入许多新的子类， 代码可能会因此变得更复杂。 最好的情况是将该模式引入创建者类的现有层次结构中。
- 与其他设计模式的关系
  - 在许多设计工作的初期都会使用[工厂方法模式](https://refactoringguru.cn/design-patterns/factory-method) （较为简单， 而且可以更方便地通过子类进行定制）， 随后演化为使用[抽象工厂模式](https://refactoringguru.cn/design-patterns/abstract-factory)、 [原型模式](https://refactoringguru.cn/design-patterns/prototype)或[生成器模式](https://refactoringguru.cn/design-patterns/builder) （更灵活但更加复杂）。
  - [抽象工厂模式](https://refactoringguru.cn/design-patterns/abstract-factory)通常基于一组[工厂方法](https://refactoringguru.cn/design-patterns/factory-method)， 但你也可以使用[原型模式](https://refactoringguru.cn/design-patterns/prototype)来生成这些类的方法。
  - 可以同时使用[工厂方法](https://refactoringguru.cn/design-patterns/factory-method)和[迭代器模式](https://refactoringguru.cn/design-patterns/iterator)来让子类集合返回不同类型的迭代器， 并使得迭代器与集合相匹配。
  - [原型](https://refactoringguru.cn/design-patterns/prototype)并不基于继承， 因此没有继承的缺点。 另一方面， *原型*需要对被复制对象进行复杂的初始化。 [工厂方法](https://refactoringguru.cn/design-patterns/factory-method)基于继承， 但是它不需要初始化步骤。
  - [工厂方法](https://refactoringguru.cn/design-patterns/factory-method)是[模板方法模式](https://refactoringguru.cn/design-patterns/template-method)的一种特殊形式。 同时， *工厂方法*可以作为一个大型*模板方法*中的一个步骤。
- 代码
  - 识别方法：工厂方法可通过构建方法来识别， 它会创建具体类的对象， 但以抽象类型或接口的形式返回这些对象
  - Creator类中可以提供一些共有的方法用于调用具体产品类中特有的操作（非必须）

- 总结：
  - 一个工厂基类、一个产品基类
  - 具体的工厂子类生成相应的具体产品类
  - 工厂基类中有一个工厂方法用于生成产品，该方法为虚函数，在子类中实现



### 抽象工厂模式

- **抽象工厂模式**是一种创建型设计模式， 它能创建**一系列相关**的对象， 而无需指定其具体类。

- 抽象工厂模式

  ![image-20210622161604202](resource\\image-20210622161604202-1624349765342.png)
  1. **抽象产品** （Abstract Product） 为构成系列产品的一组不同但相关的产品声明接口。
  2. **具体产品** （Concrete Product） 是抽象产品的多种不同类型实现。 
  3. **抽象工厂** （Abstract Factory） 接口声明了一组创建各种抽象产品的方法。
  4. **具体工厂** （Concrete Factory） 实现抽象工厂的构建方法。 每个具体工厂都对应特定产品变体， 且仅创建此种产品变体。
  5. 尽管具体工厂会对具体产品进行初始化， 其构建方法签名必须返回相应的*抽象*产品。 这样， 使用工厂类的客户端代码就不会与工厂创建的特定产品变体耦合。 **客户端** （Client） 只需通过抽象接口调用工厂和产品对象， 就能与任何具体工厂/产品变体交互。

- 适用场景

  - 如果代码需要与多个不同系列的相关产品交互，但是由于无法提前获取相关信息， 或者出于对未来扩展性的考虑， 你不希望代码基于产品的具体类进行构建， 在这种情况下，你可以使用抽象工厂。
    - 抽象工厂为你提供了一个接口， 可用于创建每个系列产品的对象。 只要代码通过该接口创建对象， 那么你就不会生成与应用程序已生成的产品类型不一致的产品。
  -  在设计良好的程序中， *每个类仅负责一件事*。 如果一个类与多种类型产品交互， 就可以考虑将工厂方法抽取到独立的工厂类或具备完整功能的抽象工厂类中。

- 优缺点

  - 优点
    - 可以确保同一工厂生成的产品相互匹配
    - 可以避免客户端和具体产品代码的耦合
    - *单一职责原则*。 你可以将产品生成代码抽取到同一位置， 使得代码易于维护。
    - *开闭原则*。 向应用程序中引入新产品变体时， 你无需修改客户端代码。
  - 缺点
    - 由于采用该模式需要向应用中引入众多接口和类， 代码可能会比之前更加复杂。

- 与其他设计模式的关系

  - 在许多设计工作的初期都会使用[工厂方法模式](https://refactoringguru.cn/design-patterns/factory-method) （较为简单， 而且可以更方便地通过子类进行定制）， 随后演化为使用[抽象工厂模式](https://refactoringguru.cn/design-patterns/abstract-factory)、 [原型模式](https://refactoringguru.cn/design-patterns/prototype)或[生成器模式](https://refactoringguru.cn/design-patterns/builder) （更灵活但更加复杂）。
  - [生成器](https://refactoringguru.cn/design-patterns/builder)重点关注如何分步生成复杂对象。 [抽象工厂](https://refactoringguru.cn/design-patterns/abstract-factory)专门用于生产一系列相关对象。 *抽象工厂*会马上返回产品， *生成器*则允许你在获取产品前执行一些额外构造步骤。
  - [抽象工厂模式](https://refactoringguru.cn/design-patterns/abstract-factory)通常基于一组[工厂方法](https://refactoringguru.cn/design-patterns/factory-method)， 但你也可以使用[原型模式](https://refactoringguru.cn/design-patterns/prototype)来生成这些类的方法。
  - 当只需对客户端代码隐藏子系统创建对象的方式时， 你可以使用[抽象工厂](https://refactoringguru.cn/design-patterns/abstract-factory)来代替[外观模式](https://refactoringguru.cn/design-patterns/facade)。
  - 你可以将[抽象工厂](https://refactoringguru.cn/design-patterns/abstract-factory)和[桥接模式](https://refactoringguru.cn/design-patterns/bridge)搭配使用。 如果由*桥接*定义的抽象只能与特定实现合作， 这一模式搭配就非常有用。 在这种情况下， *抽象工厂*可以对这些关系进行封装， 并且对客户端代码隐藏其复杂性。
  - [抽象工厂](https://refactoringguru.cn/design-patterns/abstract-factory)、 [生成器](https://refactoringguru.cn/design-patterns/builder)和[原型](https://refactoringguru.cn/design-patterns/prototype)都可以用[单例模式](https://refactoringguru.cn/design-patterns/singleton)来实现。

- 代码

  - 识别方法：会返回一个工厂对象，该工厂被用于创建特定的子组件

- 总结：

  - 一个抽象工厂类（用于客户端操作），多个具体工厂类、多个抽象产品类，多个具体产品类
  - 抽象工厂类包含生成一系列产品的接口，一个具体工厂类可以生成一系列产品对象



### 生成器模式

- **生成器模式**是一种创建型设计模式， 使你能够**分步骤创建复杂对象**。 该模式允许你使用相同的创建代码生成不同类型和形式的对象。

- 生成器模式

  ![image-20210624160425670](resource\\image-20210624160425670-1624521866926.png)
  1. **生成器 （Builder）** 接口声明在所有类型生成器中通用的产品构造步骤。
  2. **具体生成器** （Concrete Builders） 提供构造过程的不同实现。 具体生成器也可以构造不遵循通用接口的产品。
  3. **产品** （Products） 是最终生成的对象。 由不同生成器构造的产品无需属于同一类层次结构或接口。
  4. **主管** （Director） 类定义调用构造步骤的顺序， 这样你就可以创建和复用特定的产品配置。
  5. **客户端** （Client） 必须将某个生成器对象与主管类关联。 一般情况下， 你只需通过主管类构造函数的参数进行一次性关联即可。 此后主管类就能使用生成器对象完成后续所有的构造任务。 但在客户端将生成器对象传递给主管类制造方法时还有另一种方式。 在这种情况下， 你在使用主管类生产产品时每次都可以使用不同的生成器。

- 适用场景

  - 使用生成器模式可避免 “重叠构造函数 （telescopic constructor）” 的出现。
  - 当希望使用代码创建不同形式的产品 （例如石头或木头房屋） 时， 可使用生成器模式。
  - 使用生成器构造**组合树**或其他复杂对象。
    - 生成器模式让你能分步骤构造产品。 你可以延迟执行某些步骤而不会影响最终产品。 你甚至可以递归调用这些步骤， 这在创建对象树时非常方便。生成器在执行制造步骤时， 不能对外发布未完成的产品。 这可以避免客户端代码获取到不完整结果对象的情况。

- 实现方式

  - 清晰的定义通用步骤，确保他们可以制造所有形式的产品。否则无法进一步实施该模式。
  - 在基本生成器接口中声明这些步骤。
  - 为每个形式的产品创建具体生成器类， 并实现其构造步骤。
    - 需要实现获取生成产品对象的方法
  - 考虑创建主管类。 它可以使用同一生成器对象来封装多种构造产品的方式。
  - 客户端代码会同时创建生成器和主管对象。 
  - 只有在所有产品都遵循相同接口的情况下， 构造结果可以直接通过主管类获取。 否则， 客户端应当通过生成器获取构造结果。

- 优缺点

  - 优点
    - 可以分步创建对象， 暂缓创建步骤或递归运行创建步骤。
    - 生成不同形式的产品时， 你可以复用相同的制造代码。
    - *单一职责原则*。 你可以将复杂构造代码从产品的业务逻辑中分离出来。
  - 缺点
    - 由于该模式需要新增多个类， 因此代码整体复杂程度会有所增加。

- 与其他模式的关系

  - 在许多设计工作的初期都会使用[工厂方法模式](https://refactoringguru.cn/design-patterns/factory-method) （较为简单， 而且可以更方便地通过子类进行定制）， 随后演化为使用[抽象工厂模式](https://refactoringguru.cn/design-patterns/abstract-factory)、 [原型模式](https://refactoringguru.cn/design-patterns/prototype)或[生成器模式](https://refactoringguru.cn/design-patterns/builder) （更灵活但更加复杂）。
  - [生成器](https://refactoringguru.cn/design-patterns/builder)重点关注如何分步生成复杂对象。 [抽象工厂](https://refactoringguru.cn/design-patterns/abstract-factory)专门用于生产一系列相关对象。 *抽象工厂*会马上返回产品， *生成器*则允许你在获取产品前执行一些额外构造步骤。
  - 你可以在创建复杂[组合模式](https://refactoringguru.cn/design-patterns/composite)树时使用[生成器](https://refactoringguru.cn/design-patterns/builder)， 因为这可使其构造步骤以递归的方式运行。
  - 你可以结合使用[生成器](https://refactoringguru.cn/design-patterns/builder)和[桥接模式](https://refactoringguru.cn/design-patterns/bridge)： *主管*类负责抽象工作， 各种不同的*生成器*负责*实现*工作。
  - [抽象工厂](https://refactoringguru.cn/design-patterns/abstract-factory)、 [生成器](https://refactoringguru.cn/design-patterns/builder)和[原型](https://refactoringguru.cn/design-patterns/prototype)都可以用[单例模式](https://refactoringguru.cn/design-patterns/singleton)来实现。

- 代码

  - 生成器模式可以通过类来识别， 它拥有一个构建方法和多个配置结果对象的方法。 生成器方法通常支持方法链 （例如 `someBuilder->setValueA(1)->setValueB(2)->create()` ）。

- 总结

  - 基类生成器包含多个对产品修饰的函数接口，这些结构都是通用的
  - 具体生成器类需要一个返回产品的方法
  - 主管类可使用具体生成器类生成特定产品
  - 可自由使用生成器类创建产品





